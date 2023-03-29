#pragma once
#include <ostream>
class JsonValue {
  public:
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out,int ind) const = 0;
};

class NumberValue : public JsonValue {
  private:
    int value;

  public:
    NumberValue(int x);
    virtual void print(std::ostream& out, int ind) const override;
};

class StringValue : public JsonValue {
  private:
    char* string;

  public:
    StringValue(const char* value);
    virtual void print(std::ostream& out, int ind) const override;
    ~StringValue();
};

class BoolValue : public JsonValue {
  private:
    bool value;

  public:
    BoolValue(bool x);
    virtual void print(std::ostream& out, int ind) const override;
};

class NullValue : public JsonValue {
  private:
    char* value;

  public:
    NullValue();
    virtual void print(std::ostream& out, int ind) const override;
    ~NullValue();
};

class ArrayValue : public JsonValue {
  private:
    JsonValue** arr;
    int count;

  public:
    ArrayValue();
    void add(JsonValue* value);
    void print(std::ostream& out, int ind) const override;
    ~ArrayValue();
};

class ObjectValue : public JsonValue {
  private:
    JsonValue** values;
    char** fieldnames;
    int count;

  public:
    ObjectValue();
    void add(const char* name, JsonValue* value);
    operator unsigned();
    void print(std::ostream& out,int ind=0) const override;
    ~ObjectValue();
};