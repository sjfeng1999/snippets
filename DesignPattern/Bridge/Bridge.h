class BridgeImpl;

class Bridge {
  public:
    Bridge(BridgeImpl* impl);
    ~Bridge();
    void Behavior();
    int BehaviorWithParam(int param);

  private:
    // pointer to implementation
    BridgeImpl* impl_;
};
