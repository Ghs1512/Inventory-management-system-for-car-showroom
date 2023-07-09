 
#include <stdio.h>
#include <string.h>
//structure containing the car inventory member variables
  struct Car {
    char make[50];
    char model[50];
    char colour[50];
    char variant[50];
    int quant;
    int year;
    float price;
};
//structure containing the accessories inventory member variables  
  struct Acc{
    char name[50];
    float cost;
    int qt;
  }; 
//function to display the car inventory
void displayCar(struct Car car) {
    printf("Company: %s\n", car.make);
    printf("Model: %s\n", car.model);
    printf("Variant: %s\n", car.variant);
    printf("Colour: %s\n", car.colour);
    printf("Year: %d\n", car.year);
    printf("The numbers of cars available:%d\n",car.quant);
    printf("Price: Rs%.2f\n", car.price);
}
//function to display the accessories inventory
void displayAcc(struct Acc acc) {
    printf("Accessories name: %s\n", acc.name);
    printf("Cost per unit: Rs%.2f\n", acc.cost);
    printf("Quantity: %d\n", acc.qt);
}

int main() {
    struct Car inventory[100];
    struct Acc acc[100];
    int num_cars = 0;
    int num_acc =0;
    int choice;
//Printf functions to provide the output
    while (1) {
      printf("=======================================================");  
      printf("\n--------------Inventory Management System--------------\n");
        printf("1. Add a car to inventory\n");
        printf("2. View car inventory\n");
        printf("3. Search car inventory\n");
        printf("4. Add accessories to inventory\n");  
        printf("5. View the accessories inventory\n");
        printf("6. Exit\n");
        printf("=======================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        //switch case statements containing the functions to execute each option
        switch (choice) {
            case 1:
                printf("\nEnter car company: ");
                scanf("%s", inventory[num_cars].make);
                printf("Enter car model: ");
                scanf("%s", inventory[num_cars].model);
                printf("Enter car variant:");
                scanf("%s", inventory[num_cars].variant);
                printf("Enter the car colour:");
                scanf("%s", inventory[num_cars].colour);
                printf("Enter car year: ");
                scanf("%d", &inventory[num_cars].year);
                printf("Enter car price: ");
                scanf("%f", &inventory[num_cars].price);
                printf("Enter the number of cars available:");
                scanf("%d",&inventory[num_cars].quant);
                num_cars++;
                break;
            case 2:
                if (num_cars == 0) {
                    printf("\nInventory is empty!\n");
                } else {
                    printf("\nCurrent inventory:\n");
                    for (int i = 0; i < num_cars; i++) {
                        printf("\nCar %d:\n", i+1);
                        displayCar(inventory[i]);
                    }
                }
                break;
              case 3:
                printf("Searching inventory......");
                char model1[50];
                char colour1[50];
                char variant1[50];
                printf("Enter the car model:\n");
                scanf("%s",model1);
                printf("Enter the car colour:\n");
                scanf("%s",colour1);
                printf("Enter the car variant:\n");
                scanf("%s",variant1);
                for (int i = 0; i < num_cars; i++) {     
                  int p=strcmp(model1,inventory[i].model);
                  int k=strcmp(colour1,inventory[i].colour);
                  int l=strcmp(variant1,inventory[i].variant);
                  if((p == 0)&&(k == 0)&&(l==0)){      
                    displayCar(inventory[i]);
                        }
                    }
                break;
              case 4:
                printf("\nEnter accessories name: ");
                scanf("%s", acc[num_acc].name);
                printf("Enter cost of 1 unit: ");
                scanf("%f", &acc[num_acc].cost);
                printf("Enter quantity: ");
                scanf("%d", &acc[num_acc].qt);
                num_acc++;
                break;
              case 5:
                if (num_acc == 0) {
                    printf("\nInventory is empty!\n");
                } else {
                    printf("\nCurrent inventory:\n");
                    for (int i = 0; i < num_acc; i++) {
                        printf("\nAccessories %d:\n", i+1);
                        displayAcc(acc[i]);
                    }
                }
                break;
              case 6:
                printf("\nExiting program! Good Bye!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}