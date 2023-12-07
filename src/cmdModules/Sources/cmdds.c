#include "../../Includes/preprocessor.h"
#include "../Includes/cmdds.h"
#include "../../Includes/minHeap.h"
#include "../../Includes/cmdstruct.h"


static const int randArrSize= 20;

static const int minRand= 0;

static const int maxRand= 1000;

cmdstruct dscmds[]={
			{"addelem",addElem,"Adiciona elemento"},
			{"print",printElems,"Mostra elementos"},
			{"remelem",remElem,"remove elemento da queue"},
			{"genrandelems",genRand,"gerar elementos aleatorios"},
			{"sairds",sairds,"sair"},
			{"showallds",showallds,"mostrar comandos disponiveis"},
			{"destroyds",destroyds,"destroy queue"},
			{"",0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static minHeap* heap=NULL;
static comparator* comp=NULL;
void addElem(int64_t argc,int* toExit, void** argv){
	if(!comp){
		comp=malloc(sizeof(comparator));
		comp->func=(int(*)(void*,void*))compareInts;
	}
	if(!heap){
		
		heap=initMinHeap(comp,sizeof(int));
		
	}
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	insertMinHeap(heap,&elem);
}
void printElems(int64_t argc,int* toExit, void** argv){
	if(heap){

		printMinHeapPretty(heap);
	}


}

void destroyds(int64_t argc,int* toExit, void** argv){
	if(heap){

		destroyMinHeap(heap);
		heap=NULL;
	}


}


void genRand(int64_t argc,int* toExit, void** argv){
	if(!comp){
		comp=malloc(sizeof(comparator));
		comp->func=(int(*)(void*,void*))compareInts;
	}
	if(!heap){
		
		heap=initMinHeap(comp,sizeof(int));
		
	}
	if(heap){

		int* arr= getRandIntArr(minRand,maxRand,randArrSize);
		
		for(int i=0;i<randArrSize;i++){


			insertMinHeap(heap,&arr[i]);
		}
		
		free(arr);

	}


}
void remElem(int64_t argc,int* toExit, void** argv){

	if(heap){
		int* ptr=dequeueMinHeap(heap);

		printf("%d\n",*ptr);
		
		free(ptr);
	}

}



void sairds(int64_t argc,int* toExit, void** argv){
	*toExit=1;
}


void showallds(int64_t argc,int* toExit, void** argv){


			int j=0;
			while(dscmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)dscmds[j].cmdname,(char*)dscmds[j].helpdesc);
			j++;
			
			}
			printf("\n");
}


