#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsqueue.h"
#include "../../Includes/doublelist.h"
#include "../../Includes/queueList.h"
#include "../../Includes/cmdstruct.h"


static const int randArrSize= 20;

static const int minRand= 0;

static const int maxRand= 1000;

cmdstruct queuecmds[]={
			{"addelem",addElemQueue,"Adiciona elemento"},
			{"print",printElemsQueue,"Mostra elementos"},
			{"remelem",remElemQueue,"remove elemento da queue"},
			{"genrandelems",genRandQueue,"gerar elementos aleatorios"},
			{"sairds",sairQueue,"sair"},
			{"showallds",showallQueue,"mostrar comandos disponiveis"},
			{"destroyds",destroyQueue,"destroy queue"},
			{"",0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static queueList* q=NULL;


void addElemQueue(int64_t argc,int* toExit, void** argv){

	if(!q){
		
		q=initDLQueue(sizeof(int));
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	enqueueDLQueue(q,&elem);
	
}
void printElemsQueue(int64_t argc,int* toExit, void** argv){



	if(q){


		printIntList(q->list);
	}

}

void remElemQueue(int64_t argc,int* toExit, void** argv){


	if(q){
		int* ptr=dequeueDLQueue(q);

		printf("%d\n",*ptr);
		
		free(ptr);
	}


}

void genRandQueue(int64_t argc,int* toExit, void** argv){

	if(q){

		int* arr= getRandIntArr(minRand,maxRand,randArrSize);
		
		for(int i=0;i<randArrSize;i++){


			enqueueDLQueue(q,&arr[i]);
		}
		
		free(arr);

	}


}
void sairQueue(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallQueue(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(queuecmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)queuecmds[j].cmdname,(char*)queuecmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyQueue(int64_t argc,int* toExit, void** argv){

	if(q){

		destroyDLQueue(q);
		q=NULL;
	}



}



