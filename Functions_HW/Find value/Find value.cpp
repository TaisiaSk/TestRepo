#include <iostream>


bool find_value(const char** vars, const char* name, char* value, int size ) {
    int i = 0;
    while (i<size) {
        for (size_t j = 0; j < 12; ++j) {                
                if (vars[i][j] == '=') {
                    j++;
                    size_t k = 0;
                    while (vars[i][j] != '\0') {
                        value[k] = vars[i][j++];
                        ++k;
                    }
                    value[k] = '\0';
                    return true;
                }
                if (name[j] != vars[i][j])
                    break;
            }
        ++i;
    }
    return false;
 }

int main() {
    
   const char* const vars[] = { "abc=cde", "user=cap", "live=evil" };
   char value[12];

   if (find_value((const char**)vars, "live", (char*)value, sizeof(vars)/ sizeof(vars[0])))
       std::cout << value << '\n';
   else
       std::cout << "No\n";
    system("pause");
    return 0;
}