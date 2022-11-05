#include <iostream>
#include <string>

struct InitParam {
  public:
    std::string str_;
    int index_;
    float value_;

  public:
    InitParam() : str_("Default String"), index_(0), value_(0.0f) {}

    InitParam& str(const std::string& str) {
        str_ = str;
        return *this;
    }

    InitParam& index(const int idx) {
        index_ = idx;
        return *this;
    }

    InitParam& value(const float val) {
        value_ = val;
        return *this;
    }
};

class KeywordInit {
  public:
    KeywordInit(InitParam param = {}) {
        str_ = param.str_;
        index_ = param.index_;
        value_ = param.value_;
    }

    void show() {
        std::cout << "===============\n"
                  << "string : " << str_ << "\nindex_ : " << index_ << "\nvalue : " << value_ << std::endl;
    }

  private:
    std::string str_;
    int index_;
    float value_;
};

int main() {
    // default init
    KeywordInit k1{};
    // keyword init
    KeywordInit k2{InitParam().str("By keyword init").index(4)};
    k1.show();
    k2.show();
    return 0;
}
