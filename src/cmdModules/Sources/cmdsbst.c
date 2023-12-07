#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsbst.h"
#include "../../Includes/BSTcomp.h"
#include "../../Includes/cmdstruct.h"


static const int randArrSize= 20;

static const int minRand= 0;

static const int maxRand= 1000;

cmdstruct bstcmds[]={
			{"addelem",addElemBST,"Adiciona elemento"},
			{"print",printElemsBST,"Mostra elementos"},
			{"remelem",remElemBST,"remove elemento da bst"},
			{"genrandelems",genRandBST,"gerar elementos aleatorios"},
			{"sairds",sairBST,"sair"},
			{"showallds",showallBST,"mostrar comandos disponiveis"},
			{"destroyds",destroyBST,"destroy bst"},
			{"",0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static BSTreeComp* tree=NULL;
static comparator* comp=NULL;

void addElemBST(int64_t argc,int* toExit, void** argv){
	if(!comp){

		comp=malloc(sizeof(comparator));
		comp->func=(int(*)(void*,void*))compareInts;

	}
	if(!tree){
		
		tree=initBSTreeComp(sizeof(int),comp);
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	addToBSTreeComp(tree,&elem);
	
}
void printElemsBST(int64_t argc,int* toExit, void** argv){

	if(tree){



		printIntBSTreeInfixComp(tree);


	}

}

void genRandBST(int64_t argc,int* toExit, void** argv){
	if(!comp){

		comp=malloc(sizeof(comparator));
		comp->func=(int(*)(void*,void*))compareInts;

	}
	if(!tree){
		
		tree=initBSTreeComp(sizeof(int),comp);
		
	}
	
	if(tree){

		int* arr= getRandIntArr(minRand,maxRand,randArrSize);
		
		for(int i=0;i<randArrSize;i++){


			addToBSTree(tree,&arr[i]);
		}
		
		free(arr);

	}


}
void remElemBST(int64_t argc,int* toExit, void** argv){

	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	if(tree){
		int value= atoi((char*)argv[1]);
		removeFromBSTreeComp(tree,&value);

	}


}
void sairBST(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallBST(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(bstcmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)bstcmds[j].cmdname,(char*)bstcmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyBST(int64_t argc,int* toExit, void** argv){

	if(tree){
		free(comp);
		comp=NULL;
		destroyBSTreeComp(tree);
		tree=NULL;
	}



}



