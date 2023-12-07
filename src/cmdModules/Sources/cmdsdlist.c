#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsdlist.h"
#include "../../Includes/doublelist.h"
#include "../../Includes/cmdstruct.h"



static const int randArrSize= 20;

static const int minRand= 0;

static const int maxRand= 1000;

cmdstruct dlistcmds[]={
			{"addelem",addElemDList,"Adiciona elemento"},
			{"print",printElemsDList,"Mostra elementos"},
			{"remelem",remElemDList,"remove elemento da stack"},
			{"genrandelems",genRandDList,"gerar elementos aleatorios"},
			{"sairds",sairDList,"sair"},
			{"showallds",showallDList,"mostrar comandos disponiveis"},
			{"destroyds",destroyDListW,"destroy stack"},
			{"",0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static DListW* list=NULL;

void addElemDList(int64_t argc,int* toExit, void** argv){

	if(!list){
		
		list=initDList(sizeof(int));
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	addElemToListComp(list,&elem);
	
}
void printElemsDList(int64_t argc,int* toExit, void** argv){

	if(list){



		printIntList(list);


	}

}

void genRandDList(int64_t argc,int* toExit, void** argv){

	if(!list){
		
		list=initDList(sizeof(int));
		
	}
	
	if(list){

		int* arr= getRandIntArr(minRand,maxRand,randArrSize);
		
		for(int i=0;i<randArrSize;i++){


			addElemToListComp(list,arr+i);
		}
		
		free(arr);

	}


}
void remElemDList(int64_t argc,int* toExit, void** argv){

	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	if(list){
		int value= atoi((char*)argv[1]);
		remElemFromListComp(list,&value);

	}


}
void sairDList(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallDList(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(dlistcmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)dlistcmds[j].cmdname,(char*)dlistcmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyDListW(int64_t argc,int* toExit, void** argv){

	if(list){

		destroyDList(list);
		list=NULL;
	}



}



