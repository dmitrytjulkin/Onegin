#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define YEL "\e[0;33m"
#define CYN "\e[0;36m"
#define YELBG "\e[43m"
#define CRESET "\e[0m"

void read_text (char** ptr);

void print_text (char** arrptr);
int print_line (char* ptr, FILE* stream);

int strcmp_function (char* str1, char* end1, char* str2, char* end2);
int inverted_strcmp (char* str1, char* end1, char* str2, char* end2);
