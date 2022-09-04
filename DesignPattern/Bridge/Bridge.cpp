#include "Bridge.h"

class BridgeImpl {
  public:
    void Behavior() {
        // do something really;
        data_member2_ += 1;
    }

    int BehaviorWithParam(int param) {
        data_member1_ += param;
        return data_member1_;
    }

  private:
    // has real data member
    int data_member1_;
    float data_member2_;
};

Bridge::Bridge(BridgeImpl* impl) : impl_(impl) {}

Bridge::~Bridge() {}

void Bridge::Behavior() {
    return impl_->Behavior();
}

int Bridge::BehaviorWithParam(int param) {
    return impl_->BehaviorWithParam(param);
}