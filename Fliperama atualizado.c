#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void main()
{
	

	int menu;
	menuprincipal: ;
		
	printf("---------------Fliperama (v0.0.4)---------------");
	printf("\n\nInsira o numero do que deseja fazer\n\n");
	printf("1) Jogar perguntas e respostas\n");
	printf("2) Jogar advinhe o numero\n");
	printf("3) Jogar olho de cobra\n");
	printf("4) Tutorial\n");
	printf("5) Sair\n");
	scanf("%i", &menu);
	
	
	switch(menu)
	{
		//Jogo 1: perguntas e respostas:
		case 1:
		{	
		
			jogo1: ;
		
			char pergunta1[] = "Qual a capital da polonia?", pergunta2[] = "Qual o resultado de 321x11?", pergunta3[] = "Quantos tapas, aproximadamente, sao necessarios para cozinhar um frango cru?";			
			char r1a[] = "Berlim", r1b[] = "Moscou", r1c[] = "Varsovia", r2a[] = "3531", r2b[] = "3511", r2c[] = "3533", r3a[] = "135mil", r3b[] = "50mil", r3c[] = "89mil";
			int resposta, resposta2, resposta3;
			int retorno;
			//r1a = resposta da primeira questao opcao 1, e assim segue
			printf("\nPerguntas e respostas!\n");

			printf("%s", pergunta1);
			printf("\n1) %s\t2) %s\t3) %s\n", r1a, r1b, r1c);
			scanf("%i", &resposta);
			if(resposta == 3)
			{
				printf("Resposta correta!\n\n");
			}
			else
			{
				printf("Resposta incorreta!\n\nA Capital da Polonia eh 3) Varsovia!\n\n");
			}
			printf("%s", pergunta2);
			printf("\n1) %s\t2) %s\t3) %s\n", r2a, r2b, r2c);
			scanf("%i", &resposta2);
			if(resposta2 == 1)
			{
				printf("Resposta correta!\n\n");
			}
			else
			{
				printf("Resposta incorreta!\n\nO resultado de 321x11 eh 1) 3531\n\n");
			}
			printf("%s", pergunta3);
			printf("\n1) %s\t2) %s\t3) %s\n", r3a, r3b, r3c);
			scanf("%i", &resposta3);
			if(resposta3 == 1)
			{
				printf("Resposta correta!\n\n");
			}
			else
			{
				printf("Resposta incorreta!\n\nSao necessarios, aproximadamente, 1) 135 mil tapas para cozinhar um frango\n\n");
			}
			printf("Voce gostaria de jogar de novo?\n1) Jogar novamente\t2) Retornar para o menu\n");
			scanf("%i", &retorno);
			if(retorno == 1)
			{
				goto jogo1;
			}
			else
			{
				goto menuprincipal;
			}
			break;

		}
		//Jogo 2: advinhe o numero:
		case 2:
		{	
			jogo2: ;		
			
			int numeropc, numeroj, tentativas, retorno2;
			//numeropc = numero que o computador gerou . numeroj = numero que o jogador insere
			printf("\nAdvinhe o numero!\n");
			srand((unsigned)time(NULL));
			numeropc = 1 + ( rand() % 1000 );
			tentativas = 5;
			printf("O computador gerou um numero entre 1 e 1000, tente advinhar!\n");
			
			for(tentativas = 5; tentativas >= 1; tentativas--)
			{
				printf("Voce tem %i restantes\n", tentativas);
				scanf("%i", &numeroj);
				if(numeroj < numeropc)
				{
					printf("Seu numero eh MENOR que o numero do computador, tente de novo!\n");
				}
				else if(numeroj > numeropc)
				{
					printf("Seu numero eh MAIOR que o numero do computador, tente de novo!\n");
				}
				else if(numeroj == numeropc)
				{
					printf("EXATO!, voce adivinhou o numero!\n\nVoce gostaria de jogar de novo?\n1) Jogar novamente\t2) Retornar para o menu\n");
					scanf("%i", &retorno2);
					if(retorno2 == 1)
						{
							goto jogo2;
						}
						else
						{
							goto menuprincipal;
						}
				}
			}
			printf("Tentativas esgotadas!\nO numero era: %i\n\nVoce gostaria de jogar de novo?\n1) Jogar novamente\t2) Retornar para o menu\n", numeropc);
			scanf("%i", &retorno2);
			if(retorno2 == 1)
				{
					goto jogo2;
				}
				else
				{
					goto menuprincipal;						
				}
			break;
		}
		//Jogo 3: olho de cobra:
		case 3:
		{	
			jogo3: ;
			int dado1, dado2, dado3, dado4, retorno3, pontuacao1, pontuacao2, turnos, jgdnv1, jgdnv2, retorno4;
			char nome1[50];
			char nome2[50];
			
			printf("\nEsse jogo precisa de duas pessoas para ser jogado, confirme se quer iniciar:\n");
			printf("1) Iniciar\t2) Retornar ao menu\n");
			scanf("%i", &retorno3);
			if(retorno3 == 1)
			{
			printf("\nOlho de cobra!\n");
			
			printf("Insira o nome do primeiro jogador: \n");
			scanf("%s", &nome1);
			
			
			printf("\nInsira o nome do segundo jogador: \n");
			scanf("%s", &nome2);
			
			printf("\nComeco do jogo\n");
			turnos = 1;
			pontuacao1 = 0;
			pontuacao2 = 0;
			
			for(turnos = 1, pontuacao1 = 0, pontuacao2 = 0; pontuacao1 <= 50 || pontuacao2 <= 50; turnos++)
				{
					printf("Turno %i\n", turnos);
					jogador1: ;
					if(pontuacao1 < 50)
					{
					printf("Vez do %s\n", nome1);
						{
					
					srand((unsigned)time(NULL));
					dado1 = 1 + ( rand() % 6 );
					dado2 = 1 + ( rand() % 6 );
					
					printf("Os dados rolaram! E os resultados foram:\n%i\t%i", dado1, dado2);
					if(dado1 == 1 || dado2 == 1)
							{
						pontuacao1 = pontuacao1 - dado1 - dado2;
						printf("\nAzar! voce perdeu a pontuacao do seu turno\n");
						printf("%i\n", pontuacao1);
							}
					else if(dado1 == 1 && dado2 == 1)
							{
						pontuacao1 = pontuacao1 - pontuacao1;
						printf("\nOlho de cobra! voce perdeu toda sua pontuacao\n");
						printf("%i\n", pontuacao1);
							}
					else if(dado1 != 1 && dado2 != 1)
							{
						pontuacao1 = pontuacao1 + dado1 + dado2;
						printf("\npontuacao\n%i\n", pontuacao1);
						if(pontuacao1 >= 50)
								{
									goto sequenciafinal;
								}		
							}
					printf("\n\nGostaria de jogar de novo ou finalizar seu turno?\n1) jogar de novo\t2) finalizar turno\n");
					scanf("%i", &jgdnv1);
					if(jgdnv1 == 1)
							{
						goto jogador1;
							}
					else
							{
						goto jogador2;
							}
						}
					}
					else 
					{
						goto sequenciafinal;
					}
	
						
					jogador2: ;
					if(pontuacao2 < 50)
					{
					printf("Vez do %s\n", nome2);
						{	
					srand((unsigned)time(NULL));
					dado3 = 1 + ( rand() % 6 );
					dado4 = 1 + ( rand() % 6 );
					
					printf("Os dados rolaram! E os resultados foram:\n%i\t%i", dado3, dado4);
					if(dado3 == 1 || dado4 == 1)
							{
						pontuacao2 = pontuacao2 - dado3 - dado4;
						printf("\nAzar! voce perdeu a pontuacao do seu turno\n");
						printf("%i\n", pontuacao2);
							}
					else if(dado3 == 1 && dado4 == 1)
							{
						pontuacao2 = pontuacao2 - pontuacao2;
						printf("\nOlho de cobra! voce perdeu toda sua pontuacao\n");
						printf("%i\n", pontuacao2);
							}
					else if(dado3 !=1 && dado4 != 1)
							{
						pontuacao2 = pontuacao2 + dado3 + dado4;
						printf("\npontuacao\n%i\n", pontuacao2);
						if(pontuacao2 >= 50)
								{
									goto sequenciafinal;
								}
							}
					printf("\n\nGostaria de jogar de novo ou finalizar seu turno?\n1) jogar de novo\t2) finalizar turno\n");
					scanf("%i", &jgdnv2);
					if(jgdnv2 == 1)
							{
						goto jogador2;
							}
						}
					}
					else 
					{
						sequenciafinal: ;
						if(pontuacao1 >= 50)
						{
							printf("O jogador %s ganhou!\nDeseja jogar de novo?\n1) Jogar novamente\t2) Retornar para o menu\n", nome1);
							scanf("%i", &retorno4);
							if(retorno4 == 1)
							{
								goto jogo3;
							}
							else
							{
								goto menuprincipal;
							}
						}
						else if(pontuacao2 >= 50)
						{
							printf("O jogador %s ganhou!\nDeseja jogar de novo?\n1) Jogar novamente\t2) Retornar para o menu\n", nome2);
							scanf("%i", &retorno4);
							if(retorno4 == 1)
							{
								goto jogo3;
							}
							else
							{
								goto menuprincipal;
							}
						}
					}
				}
			}
			else
			{
				goto menuprincipal;
			}
				break;
		}
		//Explicando as regras de cada jogo
		case 4:
		{
			int retorno5;
			printf("1) Perguntas e respostas:\nO computador ira fazer 3 perguntas simples, responda-as usando o numero equivalente de cada alternativa\n\n");
			printf("2) Advinhe o numero:\nO computador ira pensar em um numero aleatorio entre 1 e 1000, voce tem 5 tentativas para advinhar o numero, porem,\nse voce errar, o computador ira falar se o numero inserido eh maior ou menor que o numero pensado pelo computador\n\n");
			printf("3) Olho de cobra:\nDois jogadores irao rolar dois dados por turno, os numeros dos dados serao adicionados a uma pontuacao individual para\ncada jogador, o jogador pode escolher jogar de novo ou passar seu turno, o perigo do jogo esta no fato de que se um \ndos dados rolar em 1, o jogador atual perde a pontuacao daquele turno, e se os dois dados rolarem 1, o jogador\nperde toda sua pontuacao\n\n");
			printf("4) Retornar\n");
			scanf("%i", &retorno5);
			if(retorno5 = 4)
			{
				goto menuprincipal;
			}
			break;
		}
		//Processo de saida	
		case 5:
			printf("Ate a proxima!");
			break;	
	}

}
