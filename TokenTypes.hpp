#pragma once
#include <bits/stdc++.h>

namespace APPTokenTypes
{
    enum UnitTokens
    {
        BadToken = 0,
        DivisionToken,
        MinusToken,
        MultiplicationToken,
        NewLineToken,
        NumberToken,
        PlusToken,
        WhiteSpaceToken,

        UnitTokensCount
    };
    enum KeyWordTokens
    {
        ElseKeyWordToken = UnitTokensCount,
        IfKeyWordToken,
        KeyWordTokensCount
    };

    typedef std::variant<UnitTokens, KeyWordTokens> AkariPlusPlusTokens;
    typedef std::string TokenValue;
}