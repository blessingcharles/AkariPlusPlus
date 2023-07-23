#pragma once
#include "TokenTypes.hpp"
#include <bits/stdc++.h>

namespace APPTokenTypes
{
    class SyntaxToken
    {
    private:
        AkariPlusPlusTokens _type;
        TokenValue _value;

    public:
        SyntaxToken(AkariPlusPlusTokens _type, TokenValue _value);
        AkariPlusPlusTokens getTokenType();
        TokenValue getTokenValue();
        void print();
        friend std::ostream &operator<<(std::ostream &os, SyntaxToken const &m);
    };
}