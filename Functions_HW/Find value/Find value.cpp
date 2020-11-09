#include <iostream>


bool find_value(const char** vars, const char* name, char* value) {
    size_t i = 0;
    while (vars[i++]) {
        for (size_t j = 0; j < 12; ++j) {                
                if (vars[i][j] == '=') {
                    j++;
                    for (size_t k = 0; k < (12 - j); ++k) 
                        value[k] = vars[i][j++];
                    return true;
                }
                if (name[j] != vars[i][j])
                    break;
            }
        return false;
    }
 }

int main() {
    
   const char vars[3][12] = { "abc=cde", "user=cap", "live=evil" };
   char value[12];

    std::cout<<find_value((const char**)vars, "user", (char*) value)<<'\n';//-> true, value = "cap"
    //find_value(&vars, "system", &value); //-> false

    system("pause");
    return 0;
}