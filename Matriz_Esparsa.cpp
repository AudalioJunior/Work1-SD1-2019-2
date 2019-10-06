#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
	int linha;
	int coluna;
	int valor;
	struct celula *proximo;
	struct celula *abaixo;
}Matriz;


//Criação da Matriz
Matriz* criarmatriz (){
	Matriz *m;
	m = (Matriz*)malloc(sizeof(Matriz));
	
	m->linha = 0;
	m->coluna = 0;
	m->valor = 0;
	m->abaixo = NULL;
	m->proximo = NULL;
	
	
	return m;
}

// Inserção na Matriz
int leMatriz (Matriz *A){
	system("cls");
	int linha, coluna, valor;
	Matriz *p;
	Matriz *aux1;
	Matriz *aux2;
	Matriz *novo;
	Matriz *cab_linha;
	Matriz *cab_coluna;
	
	
	//Recepçao dos valores
	printf("Digite a linha: \n");
	scanf("%d", &linha);
	printf("Digite a coluna: \n");
	scanf("%d", &coluna);
	printf("Digite o valor: \n");
	scanf("%d", &valor);
	
	
	//Primeiro caso
	if(A->abaixo == NULL || A->proximo == NULL){
		
		
		
	}
	
	

	
	//Existência da linha
	p = A;
	aux1 = p;
	Matriz *pc;

	while(p->abaixo != A){ //Verificar a lista
		printf("Entrou aqui");
			if(p->linha == linha){ // Verificar a existência da linha
				while(aux1->coluna <= coluna){ //Parar um nó antes
					aux1 = aux1->proximo;
				}
				if(aux1->proximo->coluna == coluna){ //Nó existe, retornar erro
					return -1;
				}
				else{ //Alocação do novo nó
					novo = criarmatriz();
					novo->linha = linha;
					novo->coluna = coluna;
					novo->valor = valor;
				}
					
					if(aux1->proximo->coluna > coluna){ //Tratando a linha
						novo->proximo = aux1->proximo;
						aux1->proximo = novo;
					}
					else{
						novo->proximo = p;
						aux1->proximo = novo;
					}
					
					//Tratamento da coluna
					pc = A;
					while(pc->coluna < coluna){
						pc = pc->proximo;
					}
					//Existência da cabeça	
					if(pc->proximo->coluna == coluna){
						Matriz *ant;
						aux2 = pc->proximo;
						ant = aux2;
						while(ant->linha < linha){
							ant = ant->abaixo;
						}
						Matriz *p2;
						p2 = ant->abaixo;
						ant->abaixo = novo;
						novo->abaixo = p2->abaixo;
						
					}
									
					
						
					}
p = p->abaixo;				
				}	
			
		
	
			
return 0;
}


// Apagar a Matriz
void apagaMatriz (Matriz *A){
	
}

// Somar a Matriz
void somaMatriz (Matriz *A, Matriz *B, Matriz *C){
}

// Imprimir a Matriz
void imprimeMatriz (Matriz *A){
	
}

int main(){
	Matriz *m1;
	Matriz *m2;
	Matriz *m3;
	int op;
	
	m1 = NULL;
	m2 = NULL;
	m3 = NULL;
	
	while (op != 6){
		
		printf("----------------MENU------------------ \n");
		printf("1  Criar Matriz\n");
		printf("2  Le Matriz\n");
		printf("3  Apaga Matriz\n");
		printf("4  Soma Matriz\n");
		printf("5  Imprimir Matriz\n");
		printf("6  Sair\n");
		printf("--------------------------------------- \n");
		printf("Escolha uma opcao: ");
		
		scanf("%d", &op);
		system("cls");
		
			if(op == 1){
				m1 = criarmatriz();
				printf("Matriz criada com sucesso \n");
			}
			
			if(op == 2){
				leMatriz(m1);
			}
	}
	
	
	
	
	return 0;
}
