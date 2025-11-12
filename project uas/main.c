#include "perpustakaan.h"

int main() {
    
    loginPustakawan() ;
    tampilkanMenuUtama() ;
    return 0;
}

void loginPustakawan() {
     char user [50], pass[50]
     do {
         printf("=== LOGIN PUSTAKAWAN             
         ===\n");
         printf("Username: ") ;
         scanf("%s", user) ;
         printf("Password: ") ;
         scanf("%s", pass) ;
         if(strcmp(user, " admin")==0
         && strcmp(pass, "klp1solid")==0){      
         printf("\nLogin berhasil!\n\n") ;
         break;
         } else{
              printf("Login gagal!Coba       
              lagi.\n\n") ;
         }
       
      }while(1);

}