#ifndef SP_STRUCTPARSER_H
#define SP_STRUCTPARSER_H

enum DataType {
    CHAR_ARRAY_,
    INT_,
    INT_ARRAY_,
    LONG_,
    DOUBLE_,
    DOUBLE_ARRAY_
};

struct MemberInfo {
    size_t offset;
    size_t size;
    DataType type;

    MemberInfo(size_t o, size_t s, DataType t) :
        offset(o), size(s), type(t)
    {}
};

#define OffsetOf(s,m) (size_t)&(((s*)0)->m)
#define FieldSizeOf(s,m) (size_t)sizeof(((s*)0)->m)
#define MemberInfoOf(s,m,t) OffsetOf(s,m),FieldSizeOf(s,m),t

size_t GenerateMarketDepthDataIndex(std::vector<MemberInfo>& output);

#endif