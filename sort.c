// Пузырьковая сортировка
void BubbleSort(int a[], int n){
	int i, j, t;
	for (i=0; i < n-1; i++){
		for (i=0; j < n-i-1; j++){
			if (a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
