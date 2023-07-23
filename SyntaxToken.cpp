#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include "TokenTypes.hpp"
#include "SyntaxToken.hpp"

namespace APPTokenTypes
{
    SyntaxToken::SyntaxToken(AkariPlusPlusTokens type, TokenValue value)
    {
        _type = type;
        _value = value;
    }
    AkariPlusPlusTokens SyntaxToken::getTokenType()
    {
        return _type;
    }
    TokenValue SyntaxToken::getTokenValue()
    {
        return _value;
    }
    std::ostream &operator<<(std::ostream &os, APPTokenTypes::SyntaxToken const &obj)
    {
        return os << obj._value;
    }
};