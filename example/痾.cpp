#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include <time.h>
int q[4];  //��X�n���D�ة�b�o�̡A�ݥ|�Ӧ�m
char a[500];  //�����ϥΪ̿�J���Ʀr 
int a_int[4];  //��ϥΪ̿�J���r���ন�Ʀr���b�o�|�Ӧ�m 
int ifclear = 0;  //���L�ȥΡA��ܹL���P�_�A�@�}�l��M�S�L���A�ҥH�O0 
int tocontinue = 1;  //���L�ȥΡA��ܭn�~��C���P�_ 
int toquit = 0;  //���L�ȥΡA��ܭn���X�C���P�_ 
 
void makeQ(void);  //�X�D 
void getA();  //���o�Ʀr
void outcome(void);  //��ܵ��G
void intro(void);  //���Ф�
void menu(void);  //�ϥΪ̿��
 
int main(void){  //�K�K�A�D�{���n�u�����Ӥ������� 
    intro();  //���ӭӤ��Ф�a��
    while(1==1){
        ifclear =0;
        tocontinue = 1;
        makeQ();  //�X�D
        while(tocontinue){
            getA();
        }
        if(toquit) break;
    } 
    return 0;
}

/****** ���Ф� ******/
void intro(void){
    printf("***************************************************\n");
    printf("***************************************************\n");
    printf("**                                               **\n");
    printf("**  �j���βq�Ʀr�C�� Ver1.1                      **\n");
    printf("**                                               **\n");
    printf("**  �C���W�h�G                                   **\n");
    printf("**  1.��J4�Ӥ����ƪ��Ʀr                        **\n");
    printf("**  2.�X�{A�����ƥN��A�q��F�X�ӼƦr�B��m���T  **\n");
    printf("**  3.�X�{B�����ƥN��A�q��F�X�ӼƦr����m����  **\n");
    printf("**  4.�]�N�O����4A0B���ɭԡA�N�O�A�L�����ɭ�     **\n");
    printf("**  5.���n�B�I                                   **\n");
    printf("**                                               **\n");
    printf("**  �ާ@�����G                                   **\n");
    printf("**  1.��J�|�ӼƦr����q�X��                     **\n");
    printf("**  2.��J'm'�i�H�i�J��汱��                    **\n");
    printf("**  3.��J�j���Ϊ��X�ͤ�~���|�����Q���쪺��� **\n");
    printf("**                                               **\n");
    printf("***************************************************\n");
    printf("***************************************************\n");
}
/****** �X�D��� ******/
void makeQ(void){
    int i,j;
    srand(time(0));
    for(i=0;i<4;i++){
        *(q+i) = rand()%10;
        for(j=0;j<i;j++){
            while(*(q+i) == *(q+j)){  //�o��while�O�Ψӷ�Ʀr���ƥX�{�����N�A�@�����ü�
                *(q+i) = rand()%10;
            }
        }
     
    }
}
/****** Ū�Ʀr��� ******/
void getA(){
    printf("\n�п�J: ");
    int i,j;  //�j��M�� 
    int boolin = 1;  //�ΨӪ�ܨϥΪ̬O�_���`��J
    
    fgets(a,sizeof(a),stdin);
    *(a+strlen(a)-1)= '\0'; 
    //�]��fget�u�n���\Ū���A�|�۰ʦb'\0'�e���[�W'\n'�A�ҥH�n��'\n'�ܦ�'\0'�A���M���G�|���p�w���a�h�X1
    
    if(*(a) == 'm' && strlen(a) == 1){  //�u�n�ϥΪ̤@��Jm�N�ߧY�s�X��� 
        menu();
    }else if(*a == '7' && *(a+1) == '8' && *(a+2) == '1' && *(a+3) == '1' && *(a+4) == '2' && *(a+5) == '3' && strlen(a) == 6){
        printf("�j�°����i�D�A...���׬O�G"); 
        for(i=0;i<4;i++){
            printf("%d",*(q+i));
        }
        printf("\n");
    }else{ 
        
        if(!(strlen(a)==4)){  //�P�_�ϥΪ̬O�_��J�F�|�Ӧr�� 
            boolin *=0;  //��ܨϥΪ̤����`��J 
            printf("�Ф��n��J�Ӧh�ΤӤ�\n");
        }
        for(i=0;i<strlen(a);i++){  //�P�_���ϥΪ̬O�_��J0��9 
            if(!(*(a+i) >= '0' && *(a+i) <= '9')){
                boolin *= 0;
                printf("�п�J�Ʀr0~9\n");
                break;
            }
        }
    
        for(i=0;i<4;i++){  //�P�_�ϥΪ̬O�_��J���ƼƦr 
            for(j=0;j<i;j++){
                while(*(a+i) == *(a+j)){  //�o�̩M�W�z�X�D�Ϊ��O�@�˪���z 
                    printf("�Ф��n��J���ƪ��Ʀr\n");
                    boolin *= 0;
                    break;
                }
                if(!boolin) break;
            }
            if(!boolin) break;
        }
    
        if(boolin){  //boolin�p�G����1�A�]�N�O�ϥΪ̥��`��J�A�~�}�l��r���ন�Ʀr 
            for(i=0;i<4;i++){
                *(a_int+i) = *(a+i) - '0'; 
            }
            outcome();  //�ন�Ʀr��I�soutcome�ݬݵ��G���XA�XB
        }
    }   
}
