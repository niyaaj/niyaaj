            int main(){
                int age;
                float height;
                char grade;
            
                // Input for age
                printf("Enter your age: ");
                scanf("%d", &age);
            
                // Input for height
                printf("Enter your height(cm): ");
                scanf("%f", &height);
            
                // Input for grade
                printf("Enter your grade: ");
                scanf(" %c", &grade); 
            
                // Display the entered values
                printf("\n");
                printf("Age: %d \n", age);
                printf("Height: %.2f cm \n", height);
                printf("Grade: %c \n", grade);
            
                return 0;
            }