class GridBarrier {
private:
    int* sync_workspace;

public:
    GridBarrier() = default;

    __device__ __forceinline__ void sync() const {
        volatile int* vol_sync_workspace = sync_workspace;

        // sync block work done
        __synthreads();

        int ctaid = blockIdx.x;
        int tid = threadIdx.x;

        if (ctaid == 0) {
            if (tid == 0) {
                vol_sync_workspace[ctaid] = 1;
            }
            __syncthreads();

            for (int peer_block = tid; peer_block < gridDim.x; peer_block += blockDim.x) {
                while (vol_sync_workspace[peer_block] == 0) {
                    __threadfence_block();
                }
            }
            __syncthreads();
            // notify other block to proceed
            for (int peer_block = tid; peer_block < gridDim.x; peer_block += blockDim.x) {
                vol_sync_workspace[peer_block] = 0;
            }
        } else {
            if (tid == 0) {
                vol_sync_workspace[ctaid] = 1;
                // wait block-0 sync
                while (vol_sync_workspace[ctaid] != 0) {
                    __threadfence_block();
                }
            }
            // make other threads wait thread-0
            __syncthreads();
        }
    }

};

