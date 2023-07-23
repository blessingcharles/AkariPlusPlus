#pragma once
#include <bits/stdc++.h>
#include "TokenTypes.hpp"
#include "SyntaxToken.hpp"

namespace APPLexer
{
    class Lexer
    {
    private:
        std::string text;
        uint32_t cursor = 0;
        uint32_t row = 1;
        uint32_t col = 0;
        uint32_t textlen = 0;
        void moveForward();
        void pushToken(APPTokenTypes::AkariPlusPlusTokens _type, APPTokenTypes::TokenValue _value);
        std::string parseWithCondition(std::function<bool(char)> condition);
        void parseWhiteSpace();

    public:
        Lexer(std::string text);
        std::vector<std::shared_ptr<APPTokenTypes::SyntaxToken>> tokens;
        void tokenize();
        void printTokens();
    };
}