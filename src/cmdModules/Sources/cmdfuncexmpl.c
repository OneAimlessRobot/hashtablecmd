#include "../../Includes/preprocessor.h"
#include "../Includes/cmdfuncexmpl.h"
#include "../Includes/cmdds.h"
#include "../Includes/cmdsstack.h"
#include "../Includes/cmdsbst.h"
#include "../Includes/cmdsqueue.h"
#include "../Includes/cmdsdlist.h"
#include "../Includes/cmdshashtable.h"
#include "../../Includes/cmdstruct.h"



cmdstruct commands[]={
			{"add",addNums,"printa a soma dos dois numeros que deres."},
			{"mult",multNums,"printa o produto dos dois numeros que deres."},
			{"whoami",myname,"Faz echo da string fornecida"},
			{"sair",sair,"Sair do programa"},
			{"myiq",myiq,"Mostra o teu qi"},
			{"showall",showall,"Mostra este menu"},
			{"quote",showRandomQuote,"Inspirador"},
			{"fact",factorial,"Factorial"},
			{"sumarr",sumarr,"somar array de numeros"},
			{"dsplay",dsplay,"brinca com uma estrutura de dados (minHeap)"},
			{"stackplay",stackplay,"brinca com uma estrutura de dados (stack)"},
			{"bstplay",bstplay,"brinca com uma estrutura de dados (bst)"},
			{"queueplay",queueplay,"brinca com uma estrutura de dados (queue)"},
			{"dlistplay",dlistplay,"brinca com uma estrutura de dados (double linked list)"},
			{"hashtableplay",hashtableplay,"brinca com uma estrutura de dados (hashtable)"},
			{"",0,""}
		};

#define NUMOFQUOTES 8
char* quotes[NUMOFQUOTES]={
		
		"Salivating for a violent relief",
		"My pijamas are sticking my skin. They wont come off",
		"Not being an apathetic psycho is such a pet peeve of mine",
		"Ill sleep on the grave!",
		"Statement",
		"This may sound weird but...\nI wanna rail you with my train, Nina!\nPlease!\nLets fucking destroy each other!\nWho cares if I dont have fighting skill and you do!\nGo A L L O U T on me!\n",
		"Existing",
		"I swear my coding projects are so weird...\nWho the hell am I typing all these texts for?"
};

static int64_t factorialAux(int64_t num){

	if(!num){

		return 1;
	}
	else{

		return num*factorialAux(num-1);
	}

}
void factorial(int64_t argc, int* toExit, void** argv){
	if(argc!=2){

	printf("Numero de argumenetos errado!!!\n");
		return;
	}
	int64_t arg1;
	sscanf((char*)argv[1],"%ld",&arg1);
	if(arg1<0){

		printf("Mau numero.\n");
		return;
	}
	printf("%ld\n",factorialAux(arg1));

}


void addNums(int64_t argc,int* toExit, void** argv){

	if(argc!=3){

	printf("Numero de argumentos errado!!\n");
	}
	else{
	int64_t arg1,arg2;
	sscanf((char*)argv[1],"%ld",&arg1);
	sscanf((char*)argv[2],"%ld",&arg2);
	printf("%ld\n", arg1+arg2);

	}

}


void showRandomQuote(int64_t argc,int* toExit, void** argv){


          struct timespec time;

          clock_gettime(CLOCK_REALTIME, &time);
          srand(time.tv_nsec);

	int posInVec= genRandInt(0, NUMOFQUOTES-1);

	printf("%s\n", quotes[posInVec]);


}

void multNums(int64_t argc,int* toExit, void** argv){


	if(argc!=3){

	printf("Numero de argumentos errado!!\n");
	}
	else{
	
	double arg1,arg2;
	sscanf((char*)argv[1],"%lf",&arg1);
	sscanf((char*)argv[2],"%lf",&arg2);
	printf("%lf\n", arg1*arg2);
	}

}
void myname(int64_t argc,int* toExit, void** argv){

	if(argc!=2){

	printf("Numero de argumentos errado!!\n");
	}
	else{
	
	printf("%s\n",(char*)argv[1]);
	}

}

void myiq(int64_t argc,int* toExit, void** argv){

	  struct timespec time;

          clock_gettime(CLOCK_REALTIME, &time);
          srand(time.tv_nsec);

	printf("O teu qi neste momento e: %d\n",genRandInt(0,10000));


}

void sair(int64_t argc,int* toExit, void** argv){
	*toExit=1;
}


void showall(int64_t argc,int* toExit, void** argv){


			int j=0;
			while(commands[j].cmdname[0]){
			printf("%s- %s\n",(char*)commands[j].cmdname,(char*)commands[j].helpdesc);
			j++;
			
			}
			printf("\n");
}


void sumarr(int64_t argc, int* toExit, void** argv){
	
	if(!argv){

		printf("Nao tens argumentos eeiiiadizer\n");
		return;
	}
	int numOfElems=0;
	int64_t total=0;
	while(argv[numOfElems]){

		int64_t nextToSum=0;
		sscanf((char*)argv[numOfElems],"%ld",&nextToSum);
		total+=nextToSum;
		numOfElems++;
	}
	printf("Total: %ld\n",total);


}

void dsplay(int64_t argc,int* toExit, void** argv){

hashtablecomp*cmdLine=initCmdLine(dscmds);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);



}

void stackplay(int64_t argc,int* toExit, void** argv){

hashtablecomp*cmdLine=initCmdLine(stackcmds);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);



}

void queueplay(int64_t argc,int* toExit, void** argv){

hashtablecomp*cmdLine=initCmdLine(queuecmds);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);



}

void dlistplay(int64_t argc,int* toExit, void** argv){

hashtablecomp*cmdLine=initCmdLine(dlistcmds);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);



}
void bstplay(int64_t argc,int* toExit, void** argv){

hashtablecomp*cmdLine=initCmdLine(bstcmds);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);



}

void hashtableplay(int64_t argc,int* toExit, void** argv){

hashtablecomp*cmdLine=initCmdLine(hashtablecmds);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);



}
