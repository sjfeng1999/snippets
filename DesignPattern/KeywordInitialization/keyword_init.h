enum class Type {
    kDefault,
    kMatrix,
    kActivation,
};

struct InitParam {
  public:
    Type type_;
    int index_;
    float value_;

  public:
    InitParam() : type_(Type::kDefault), index_(0), value_(0.0f) {}

    InitParam& type(Type t) { 
        type_ = t;   
        return *this;
    }
    InitParam& index(int idx) { 
        index_ = idx;
        return *this;
    }
    InitParam& value(float val) {
        value_ = val;
        return *this;
    }
};

class KeywordInit {
  public:
    KeywordInit(InitParam param = {});

  private: 
    Type type_;
    int index_;
    float value_;
};

