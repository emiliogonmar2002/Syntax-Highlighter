#ifndef HTMLCREATOR_H
#define HTMLCREATOR_H

#include<vector>
#include<iostream>
#include<unordered_map>
#include<fstream>
#include <sstream>

class HTMLcreator{

    public:
        HTMLcreator(std::vector<std::string> re_vector, std::vector<std::string> token_vector);
        void createHTML();

    private:
        std::vector<std::string> re_vector;
        std::vector<std::string> token_vector;

};

HTMLcreator::HTMLcreator(std::vector<std::string> re_vector_, std::vector<std::string> token_vector_){
    re_vector = re_vector_;
    token_vector = token_vector_;
}

void HTMLcreator::createHTML(){
    std::ofstream file;
    std::ifstream in_file("text_file.txt");

    std::string token_type, word, line;

    std::unordered_map<std::string, std::string> tokentype_color;

    // generar los colores necesarios para los tokens
    std::vector<std::string> colors = {"#FF8C00","#FFD700","#7FFFD4","#6B8E23","#FFA07A","#FF0000","#CD5C5C","#DB7093","#20B2AA","#4682B4","#800000","#BDB76B","#EE82EE","#9400D3"};

    for(int i=0;i<re_vector.size();i++){
        tokentype_color[std::to_string(i)] = colors[i];
    }
    tokentype_color[std::to_string(re_vector.size())] = "black";

    file.open("webpage.html",std::ios::out);

    file<< "<!DOCTYPE html> \n <html> \n <head> \n <title>Syntax Highlighter</title>\n </head>\n <body style=\"text-align:center;font-size:25px;\">\n\n";

    file<<"<p>";
    while(!in_file.eof()){
        getline(in_file, line);

        if(line != ""){
            std::stringstream input_stringstream(line);

            getline(input_stringstream, token_type, ' ');
            getline(input_stringstream, word);
            file<<"<span style=\"color:"<<tokentype_color[token_type]<<"\";>"<<word<<"</span>";
        }
        else{
            file<<"</p>";
            file<<"<p>";
        }
        
    } 
    
    file<< "\n </font></body>\n</html>\n ";

    file.close();
}

#endif