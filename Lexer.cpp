#include <bits/stdc++.h>
#include "Lexer.hpp"
#include "TokenTypes.hpp"

namespace APPLexer
{
    Lexer::Lexer(std::string text)
    {
        this->text = text;
        this->textlen = text.length();
    }
    void Lexer::moveForward()
    {
        if (text[cursor] == '\n')
        {
            do
            {
                row++;
                col = 0;
            } while (text[++cursor] == '\n');
        }
        cursor++;
    }
    void Lexer::pushToken(APPTokenTypes::AkariPlusPlusTokens type, APPTokenTypes::TokenValue value)
    {
        tokens.push_back(std::shared_ptr<APPTokenTypes::SyntaxToken>(new APPTokenTypes::SyntaxToken(type, value)));
    }

    std::string Lexer::parseWithCondition(std::function<bool(char)> condition)
    {
        uint32_t initPos = cursor;
        do
        {
            moveForward();
        } while (cursor != textlen && condition(text[cursor]));
        return text.substr(initPos, cursor - initPos);
    }
    void Lexer::parseWhiteSpace()
    {
    }
    void Lexer::tokenize()
    {
        std::string value;
        while (cursor != textlen)
        {
            switch (text[cursor])
            {
            case '+':
                pushToken(APPTokenTypes::PlusToken, "+");
                moveForward();
                break;
            case '-':
                pushToken(APPTokenTypes::MinusToken, "-");
                moveForward();
                break;
            case '*':
                pushToken(APPTokenTypes::MultiplicationToken, "*");
                moveForward();
                break;
            case '/':
                pushToken(APPTokenTypes::DivisionToken, "/");
                moveForward();
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value = parseWithCondition([](char ch) -> bool
                                           { return isdigit(ch); });
                pushToken(APPTokenTypes::NumberToken, value);
                break;
            case ' ':
                value = parseWithCondition([](char ch) -> bool
                                           { return ch == ' '; });
                pushToken(APPTokenTypes::WhiteSpaceToken, value);
                break;
            default:
                moveForward();
                break;
            }
        }
    }
    void Lexer::printTokens()
    {
        for (std::shared_ptr<APPTokenTypes::SyntaxToken> &token : this->tokens)
        {
            std::cout << token->getTokenValue() << " : " << token->getTokenValue().length() << std::endl;
        }
    }
}