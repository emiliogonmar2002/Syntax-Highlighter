#ifndef LEXCREATOR_H
#define LEXCREATOR_H

#include<string>
#include<vector>
#include<fstream>
#include<iostream>

class LexCreator {
    public:
        LexCreator();
        LexCreator(std::string re_file);

        std::vector<std::string> getRe_vector();
        std::vector<std::string> getToken_vector();

        void readRegularExpressions();
        void createLexFile();

    private:
        std::vector<std::string> re_vector;
        std::vector<std::string> token_vector;
        std::string re_file;
};

LexCreator::LexCreator(std::string re_file_){
    re_file = re_file_;
}

std::vector<std::string> LexCreator::getRe_vector(){
    return re_vector;
}

std::vector<std::string> LexCreator::getToken_vector(){
    return token_vector;
}

void LexCreator::readRegularExpressions(){
    
    std::ifstream file(re_file);
    
    std::string regular_expression, token_type;

    while(!file.eof()){
        getline(file, regular_expression, ' ');
        getline(file,token_type);

        re_vector.push_back(regular_expression);
        token_vector.push_back(token_type);
    }
}

void LexCreator::createLexFile(){
    std::ofstream file;
    file.open("lexfile.l",std::ios::out);

    // write format to .l file
    file<<"%{\n";
    file<<"%}\n";

    // write regular expression

    file<<"%%\n";
    // file<<"\"\\n\"\n";
    // file<<" \n";
    // file<<"\"\\t\"\n";
    for (int i=0; i<re_vector.size(); i++){
        file << re_vector[i] << " " << "{fprintf(yyout,\"" << i << " \");fprintf(yyout,yytext);fprintf(yyout,\"\\n\");}" << "\n";
    }
    file<<". {fprintf(yyout,\"" << re_vector.size() << " \");fprintf(yyout,yytext);fprintf(yyout,\"\\n\");}\n";
    file<<"%%\n";

    // write final part of .l file
    file<<"int yywrap(void){\n\treturn 1;\n}";

    file.close();
}


#endif //LEXCREATOR_H