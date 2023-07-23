#include <iostream>
#include <bits/stdc++.h>
#include "AppRepl.hpp"
#include "Lexer.hpp"
#include "SyntaxToken.hpp"

namespace APPRepl
{
    void AkariPlusPlusRepl::run()
    {
        std::string text;
        while (true)
        {
            std::cout << ">> ";
            std::getline(std ::cin, text);
            if (text == "@quit" or text == "@exit")
                break;
            std::unique_ptr<APPLexer::Lexer> lexer(new APPLexer::Lexer(text));
            lexer->tokenize();
            lexer->printTokens();
        }
    }
}