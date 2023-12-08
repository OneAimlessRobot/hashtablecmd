#include "../../Includes/preprocessor.h"
#include "../Includes/cmdshashtable.h"
#include "../../Includes/comparator.h"
#include "../../Includes/hasher.h"
#include "../../Includes/hashtablecomp.h"
#include "../../Includes/cmdstruct.h"

#define STRINGLENGTH 10

static const int randArrSize= 20;

cmdstruct hashtablecmds[]={
			{"addelem",addElemHashTable,"Adiciona elemento"},
			{"print",printElemsHashTable,"Mostra elementos"},
			{"remelem",remElemHashTable,"remove elemento da stack"},
			{"genrandelems",genRandHashTable,"gerar elementos aleatorios"},
			{"sairds",sairHashTable,"sair"},
			{"showallds",showallHashTable,"mostrar comandos disponiveis"},
			{"destroyds",destroyHashTable,"destroy stack"},
			{"",0,""}
		};
static int compareStrings(void* a,void*b){

	
	return strcmp((char*)a,(char*)b);

}


static int64_t hashString(char* string){


 u_int64_t hash= 5381;

         u_int64_t count=0;

 for(;count<STRINGLENGTH;count++){

 hash= ((hash << 5) + hash) +string[count];
 }
 return hash;
 }


static comparator* comp=NULL;

static hasher* hfunc =NULL;
static hashtablecomp* ht=NULL;

void addElemHashTable(int64_t argc,int* toExit, void** argv){
	if(!comp){

		comp=malloc(sizeof(comparator));
		comp->func=compareStrings;
	}
	if(!hfunc){
		hfunc=malloc(sizeof(hasher));
		hfunc->func=hashString;


	}
	if(!ht){
		
		ht=initHashTableComp(STRINGLENGTH,comp,hfunc);
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	char buff[STRINGLENGTH];
	memset(buff,0 ,STRINGLENGTH);
	memcpy(buff,argv[1],min(STRINGLENGTH-1,strlen(argv[1])));
	addToHTComp(&ht,buff);
	
}
void printElemsHashTable(int64_t argc,int* toExit, void** argv){

	if(ht){


		printHashTableComp(ht);
	}

}

void genRandHashTable(int64_t argc,int* toExit, void** argv){
	if(!comp){

		comp=malloc(sizeof(comparator));
		comp->func=compareStrings;
	}
	if(!hfunc){
		hfunc=malloc(sizeof(hasher));
		hfunc->func=hashString;


	}
	if(!ht){
		
		ht=initHashTableComp(STRINGLENGTH,comp,hfunc);
		
	}
	if(ht){

		char** arr= randStrArr(STRINGLENGTH-1,randArrSize);
		
		for(int i=0;i<randArrSize;i++){

			char buff[STRINGLENGTH];
			memset(buff,0 ,STRINGLENGTH);
			memcpy(buff,arr[i],min(STRINGLENGTH-1,strlen(arr[i])));
			addToHTComp(&ht,buff);
		}
		
		freeStrArr(arr,randArrSize);

	}


}
void remElemHashTable(int64_t argc,int* toExit, void** argv){

	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	if(ht){
		removeFromHTComp(ht,argv[1]);

	}


}


void sairHashTable(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallHashTable(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(hashtablecmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)hashtablecmds[j].cmdname,(char*)hashtablecmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyHashTable(int64_t argc,int* toExit, void** argv){

	if(comp){

		free(comp);
		comp=NULL;
	}
	if(hfunc){

		free(hfunc);
		hfunc=NULL;
	}
	if(ht){

		destroyHashTableComp(ht);
		ht=NULL;
	}


}


