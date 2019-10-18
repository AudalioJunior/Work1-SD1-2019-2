#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
	int lin;
	int col;
	int valor;
	struct celula *proxlin;
	struct celula *proxcol;
}matriz;


//Criação da Matriz
matriz* criarmatriz (){
	matriz *m;
	m = (matriz*)malloc(sizeof(matriz));
	
	m->lin = 0;
	m->col = 0;
	m->valor = 0;
	m->proxlin = m;
	m->proxcol = m;
		
	
	return m;
}

//Verifica se minha matriz está vazia
int matrizVazia(matriz* A){
	
	if((A->proxlin == A) && (A->proxcol == A)){
		return 1;
	}
	else{
		return 0;
	}
}


//Função para lidar com o encadeamento da Matriz
matriz* encadeia(matriz *A, matriz *nova){
	if(matrizVazia(A)){
		matriz* novalin = (matriz*)malloc(sizeof(matriz));
		matriz* novacol = (matriz*)malloc(sizeof(matriz));
		
		novalin->lin = nova->lin;
		novalin->col = 0;
		
		novacol->col = nova->col;
		novacol->lin = 0;
		
		A->proxlin = novalin;
		A->proxcol = novacol;
		
		novalin->proxcol = nova;
		novalin->proxlin=A;
		novacol->proxlin = nova;
		novacol->proxcol=A;
		
		nova->proxlin = novacol;
		nova->proxcol = novalin;
		return A;
	}
	else{
		matriz* ant = A;
		matriz* aux = A->proxlin;
		while(aux!=A){
			if(aux->lin == nova->lin) break;
			if(aux->lin > nova->lin) break;
			ant = aux;
			aux = aux->proxlin;
		}		
		if(aux == A){
			matriz* novalin = (matriz*)malloc(sizeof(matriz));
			
			novalin->lin = nova->lin;
			novalin->col = 0;
			
			novalin->proxlin = A;
			ant->proxlin = novalin;
			novalin->proxcol = nova;
			nova->proxcol=novalin;
		}
		else if(aux->lin > nova->lin){
			matriz* novalin = (matriz*)malloc(sizeof(matriz));
			
			novalin->lin = nova->lin;
			novalin->col = 0;
			
			novalin->proxlin = aux;
			ant->proxlin = novalin;
			novalin->proxcol = nova;
			nova->proxcol=novalin;
		}
		else{
			if(aux->lin == nova->lin){
				if(aux->proxcol == aux){
					aux->proxcol = nova;
					nova->proxcol = aux;
				}else{
					matriz* percorreColdaLin = aux->proxcol;
					matriz* antPercorreColdaLin = aux;
					while(percorreColdaLin != aux){
						if(percorreColdaLin->col > nova->col){
							break;
						}
						antPercorreColdaLin = percorreColdaLin;
						percorreColdaLin = percorreColdaLin->proxcol;
					}
					if(percorreColdaLin == aux){
						antPercorreColdaLin->proxcol = nova;
						nova->proxcol = percorreColdaLin;
					}else{
						nova->proxcol = percorreColdaLin;
						antPercorreColdaLin->proxcol = nova;
					}
				}
			}
		}
		ant=A;
		matriz* temp1=A->proxcol;
		while(temp1!=A){
			if(temp1->col==nova->col) break;
			if(temp1->col>nova->col) break;
			ant=temp1;
			temp1=temp1->proxcol;
		}		
		if(temp1 == A){
			matriz* aux;
			matriz* novacol = (matriz*)malloc(sizeof(matriz));
			
			novacol->col = nova->col;
			novacol->lin = 0;
			
			novacol->proxcol = temp1;
			ant->proxcol = novacol;
			novacol->proxlin = nova;
			nova->proxlin = novacol;
		}
		else if(temp1->col > nova->col){
			matriz* novacol = (matriz*)malloc(sizeof(matriz));
			
			novacol->col = nova->col;
			novacol->lin = 0;
			
			novacol->proxcol = temp1;
			ant->proxcol = novacol;
			novacol->proxlin = nova;
			nova->proxlin = novacol;
		}
		else{
			if(temp1->col == nova->col){
				if(temp1->proxlin == A){
					ant->proxlin = nova;
					nova->proxlin = temp1;
				}else{
					matriz* aux1 = temp1->proxlin;
					matriz* aux2 = temp1;
					while(aux1 != temp1){
						if(aux1->lin > nova->lin) break;
						else{
							aux2 = aux1;
							aux1 = aux1->proxlin;
						}
					}
					if(aux1 == temp1){
						aux2->proxlin = nova;
						nova->proxlin = aux1;
					}else{
						nova->proxlin = aux1;
						aux2->proxlin = nova;
					}
				}
			}
		}
		return A;
	}
}


matriz *leMatriz (matriz *A){
	int lin, col, val;

	while(lin != -1 || col != -1){
		printf("Digite a linha: \n");
		scanf("%d", &lin);
		if(lin == -1) return A;
		printf("Digite a coluna: \n");
		scanf("%d", &col);
		if(col == -1) return A;
		printf("Digite o valor: \n");
		scanf("%d", &val);
		system("cls");
		printf("LEITURA REALIZADA COM SUCESSO \n");
		
			matriz* novo; 
			novo = (matriz*)malloc(sizeof(matriz));
			novo->col=col;
			novo->lin=lin;
			novo->valor = val;
			novo->proxlin = NULL;
			novo->proxcol = NULL;
			A = encadeia(A, novo);
	}
	

return A;
}
// Apagar a Matriz
void apagaMatriz (matriz *A){
	
	matriz *p1, *base, *p, *aux, *aux2;
	
	base = A;

	
	while(aux != base){
		p = base;		

		while(p->proxlin != base){ //Tratamento das linhas
			p = p->proxlin;
		}
		 p1 = base;
		while(p1->proxlin != p){
			p1 = p1->proxlin;
		}
		if(p->proxlin == base){ //Se tudo der certo
			aux = p;
			while(aux->proxcol != p){ //Tratamento das colunas
				aux = aux->proxcol; //Chegando no último valor
			}		
			aux2 = p;
			while(aux2->proxcol != aux){ //Tratar para não perder o ponteiro
				aux2 = aux2->proxcol;
			}
			if(aux = p){
				p1->proxlin = p->proxlin;
				free(p);
			}
			else{
			aux2->proxcol = aux2->proxcol->proxcol; //Ponteiro guardado
			aux->proxcol = NULL;
			aux->proxlin = NULL;
			free(aux);
			}
		}
	}
	
free(A);
}

// Imprimir a Matriz
void imprimeMatriz (matriz *A){
matriz *p;
matriz *aux;

p = A->proxlin;

while(p != A){
	aux = p;
	aux = aux->proxcol;
		while(aux != p){
			printf(" [%d]", aux->valor);
			aux = aux->proxcol;
		}
	p = p->proxlin;
	printf(" \n");
}

}

// Somar a Matriz
void somaMatriz (matriz *A, matriz *B, matriz *C){
	matriz* p = A;
	matriz* p1 = B;
	int i = 0;
	
	//Tratamento da primeira matriz
	while(p->proxlin != A){
		p = p->proxlin;
	}
	matriz* aux = p;
	while(aux->proxcol != p){
		aux = aux->proxcol;
	}
	
	//Tratamento da segunda matriz
	while(p1->proxlin != B){
		p1 = p1->proxlin;
	}
	matriz* aux2 = p1;
	while(aux2->proxcol != p1){
		aux2 = aux2->proxcol;
	}
	
	if(p->lin == p1->lin){
		if(p->col == p1->col){ //Pode somar
			p = A;	
		//Clonar a matriz A na C
			while(p->proxlin != A){
				p = p->proxlin;
				aux = p;
					while(aux->proxcol != p){
						aux = aux->proxcol;
						matriz* novo = (matriz*)malloc(sizeof(matriz));
						novo->lin = p->lin;
						novo->col = aux->col;
						novo->valor = aux->valor;
						C = encadeia(C, novo);
					}
			}
			//Clonada com sucesso
			//Startar a soma
			p1 = B;
			matriz *p2 = C;
			while(p1->proxlin != B){
				matriz *p2 = C;
				p1 = p1->proxlin;
					while(p2->proxlin != C){
						p2 = p2->proxlin;
							if(p1->lin == p2->lin){
								aux = p1;
									while(aux->proxcol != p1){
										aux = aux->proxcol;
											aux2 = p2;
											while(aux2->proxcol != p2){
												aux2 = aux2->proxcol;
													if(aux->col == aux2->col){
														aux2->valor = aux->valor + aux2->valor;		
													}
													else{
														matriz* novo1 = (matriz*)malloc(sizeof(matriz));
														novo1->lin = aux->lin;
														novo1->col = aux->col;
														novo1->proxcol = NULL;
														novo1->proxlin = NULL;
														novo1->valor = aux->valor;
														C = encadeia(C, novo1);
													}
											}
									}
							}
						
					}
			}
			
		}
		imprimeMatriz(C);
	}	
	else{//Retorna erro
		printf("Erro: As matrizes nao possuem a mesma dimenssao \n");
		printf(" \n");
	}
}

int main(){
	matriz *m1, *m2, *m3;
	int op, op1;
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
			if(m1 == NULL){
			m1 = criarmatriz();
			printf("Matriz 1 criada com sucesso! \n");
			printf("\n");
		}
		else{
		m2 = criarmatriz();
		printf("Matriz 2 criada com sucesso! \n");
		printf("\n");
			}
					
		}
		
		if(op == 2){
		
			printf("Qual matriz deseja fazer a leitura: \n");
			printf("Matriz 1 \n");
			printf("Matriz 2 \n");
			op1 = 0;
			scanf("%d", &op1);
			
			if(op1 == 1){
				if(m1 == NULL){
					printf("ERROR: MATRIZ NAO INICIALIZADA \n");
				}
				else{
					m1 = leMatriz(m1);
				}
			}
			if(op1 == 2){
				if(m2 == NULL){
					printf("ERROR: MATRIZ NAO INICIALIZADA \n");
				}
				else{
					m2 = leMatriz(m2);
				}
			}
			
			if(op1 != 1 || op1 != 2){
				printf("Opcao indisponivel \n");
			}
				
		}
		
		if(op == 3){
			printf("Qual matriz deseja apagar: \n");
			printf("Matriz 1 \n");
			printf("Matriz 2 \n");
			op1 = 0;
			
			scanf("%d", &op1);
			if(op1 == 1){
				if(m1 == NULL){
					printf("ERROR: MATRIZ NAO INICIALIZADA \n");
				}
				else{
					apagaMatriz(m1);
					m1 = NULL;
				}
			}
			if(op1 == 2){
				if(m2 == NULL){
					printf("ERROR: MATRIZ NAO INICIALIZADA \n");
				}
				else{
					apagaMatriz(m2);
					m2 = NULL;
				}
			}
			if(op1 != 1 || op1 != 2){
				printf("Opcoes nao encontradas \n");
			}
		}
		if(op == 4){
			m3 = criarmatriz();
			somaMatriz(m1, m2, m3);
		}
		
		if(op == 5){
			printf("Qual matriz deseja imprimir: \n");
			printf("Matriz 1 \n");
			printf("Matriz 2 \n");
			op1 = 0;
			scanf("%d", &op1);
			if(op1 == 1){
				if(m1 == NULL){
					printf("ERROR: MATRIZ VAZIA \n");
				}else{
					imprimeMatriz(m1);
				}
			}
			
			if(op1 == 2){
				if(m2 == NULL){
					printf("ERROR: MATRIZ VAZIA \n");
				}else{
					imprimeMatriz(m2);
				}
			}
		}
}
	printf("by AudalioJunior");
	return 0;
}
