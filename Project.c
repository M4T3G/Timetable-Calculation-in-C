#include <stdio.h>
#define MAX 50

void isKoduAlma(int (*matris)[3],int n);
int oncekilerleKiyas(int matrix[][3], int anlikIndeks, int n,int isKodu);
void ekranaYazdirma(int matrix[][3],int n,int head);

int main(){
	int n,head,i,linkedSayi,j;
	int matris[MAX][3];
	int LinkedList[MAX];
	printf("Is sayisini giriniz: ");
	scanf("%d",&n);
	isKoduAlma(matris,n);
	printf("\nLinked listinizin head degerini giriniz: ");
	scanf("%d",&head);
	for(i=0; i<n; i++){
		printf("%c isi icin bu isin linklendigi sayiyi giriniz: ",matris[i][0]+'A');
		scanf("%d",&linkedSayi);
		matris[i][2] = linkedSayi; 
	}
	ekranaYazdirma(matris,n,head);

	return 0;
}

void ekranaYazdirma(int matrix[][3],int n,int head){
	int i,j,siradakiLinkedList;
	printf("Matrisiniz: \n");
	for(i=0; i<n; i++){
		for(j=0; j<3; j++){
			if(j==0){
				printf(" %c ",matrix[i][j]+'A');
			}
			else{
				printf(" %d ",matrix[i][j]);
			}
	}
	printf("\n");
}
printf("Islerin zaman cizelgesi: ");

do{
	j = head;
	for(i=0; i<matrix[head][1]; i++){
		printf(" %c",matrix[head][0]+'A');
	}
	head = matrix[head][2];
}while(head != -1);

}
void isKoduAlma(int (*matris)[3],int n){
	int i;
	char isKodu;
	int isKodutmp;
	int isSuresi;
	for(i=0;i<n;i++){
		do{
			printf("\n%d. is kodunuzu oncekilerden farkli sekilde giriniz: ",i+1);
			scanf(" %c",&isKodu);
			isKodutmp = isKodu - 'A';
			matris[i][0] = isKodutmp;
		}while(oncekilerleKiyas(matris,i,n,isKodutmp));
	}
	for(i=0; i<n; i++){
		printf("%c isi icin bu isin tamamlanma suresini giriniz: ",matris[i][0]+'A');
		scanf("%d",&isSuresi);
		matris[i][1] = isSuresi;
	}
}


int oncekilerleKiyas(int matrix[][3], int anlikIndeks, int n,int isKodu){
    int i = 0;
    for (i = 0; i < anlikIndeks; i++) {
        if (matrix[i][0] == isKodu) {
            return 1;
        }
    }
    return 0;
}
