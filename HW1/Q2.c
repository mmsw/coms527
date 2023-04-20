/*
   The correction of the program will be in annotation

*/

#include <stdlib.h>

typedef struct 
{
    char* street;
    int number;
    int post_code;
    char* city;
} address;

address* create_address (char* street, int number, int post_code, char* city)
{
    // In order to create a struct, we need to allocate memory for the struct
    address* new_address = (address *)malloc(sizeof(address));
    new_address->street = street;
    new_address->number = number;
    new_address->post_code = post_code;
    new_address->city = city;
    return new_address;
}

/*
    To transfer the data properly, the best way is to deliver 
    pointer of the struct instead of struct itself. 
*/ 
address* duplicate_address(address *orig) 
{
    // new struct need memory, allocate memory first
    address* new_address = (address *)malloc(sizeof(address));
    /* To duplicate new struct, we need to copy the value 
       of the original one to new memory. Using something 
       like "new_address = orig" can only duplicate pointer,
       the data on the memory do not duplicate. 
    */
    new_address->street = orig->street;
    new_address->number = orig->number;
    new_address->post_code = orig->post_code;
    new_address->city = orig->city;
    return new_address;
}

int main()
{
    address* a1 = create_address("Mornewegstr.", 30, 64293, "Darmstadt");

    // a1 is the address pointer, "&a1" is type "address**"". We need to delete "&"
    address* a2 = duplicate_address(a1);

    free(a1);
    free(a2);
}