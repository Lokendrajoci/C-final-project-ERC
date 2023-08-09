#define _GNU_SOURCE
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define size 2000
void Initializing_Display();
void option_display();
void half_test();
void full_test();
void user_response_print();
void test_cover_display();
void answer_checker(char *correct_answer, char *option1, char *option2, char *option3, char *option4, int *fscore, FILE *user_response);
void student_record();
bool citizenship_checker(const char *citizen_shp);
void display_file();
void id_for_test_checker();
void citizenship_id_maker();
void leader_board();
void view_leaderboard();
void view_students();
bool password_checker();


typedef struct student_personal_information
{

    char name[50];
    char date_of_birth[50];
    char citizenship_number[20];
} std_rec;

int main()
{

    Initializing_Display();
     char to_continue;
     do
     {
        fflush(stdin);
        option_display();
         system("pause");
         system("cls");
         printf("ENTER 'y' or 'Y' to continue, 'x' or 'X' to exit: ");
         scanf(" %c", &to_continue);

     } while (to_continue != 'x' || to_continue != 'X');

    return 0;
}

void Initializing_Display() // This function contains the statements that shows the information about the developers of the project.
{
    char continue_input;

    printf("\nComputer Programming Project:\n\n\t\t_________________________________________________________________________\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t Project By:\t\t\t\t|\n\t\t|\t\t\t\t*************\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");

    printf("\t\t|\t\t\t1. Lokendra Joshi(PUR079bct036)\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|\t\t\t2. Aayush Rauniyar(PUR079bct02)\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|\t\t\t3. Mihir Gupta(PUR079bct040)\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|\t\t\t4. Basanta Raj Khatiwada(PUR079bct017)\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");

    printf("\t\t| Faculty: Department of Electronics and Computer Engineering.\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t| Semester: 1st\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t| College: IOE PURWANCHAL .\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t| Enrolled Year : 2079 B.S.\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|_______________________________________________________________________|\n\n");
    do // This loop is to keep on asking the user to enter "Enter" to continue until the user presses Enter.
    {
        printf("Press Enter to Continue...\n");
        fflush(stdin);
        continue_input = getchar();
    } while (continue_input != '\n');
}

void option_display()
{
    int student_choice;
    printf("ENTER THE NUMBERS TO CHOOSE THE RESPECTIVE OPTIONS:\n\n\n");
    printf("1. Enroll Yourself!\n\n");
    printf("2. Take practise Test(You can choose the number of questions.)\n\n");
    printf("3. Take Full Mock Test.\n\n");
    printf("4. View the Leader-Board\n\n");
    printf("5. View All Enrolled Students.(Admins Only)\n\n");
    printf("6. Exit.\n\n");
    scanf("%d", &student_choice);
    system("cls");
    fflush(stdin);
    if (student_choice == 1)
    {
        student_record();
        citizenship_id_maker();
        // display_file();
    }

    else if (student_choice == 2)
    {
        id_for_test_checker();
        test_cover_display();
        fflush(stdin);
        half_test();
    }

    else if (student_choice == 3)
    {
        system("cls");
        id_for_test_checker();
        test_cover_display();
        fflush(stdin);
        full_test();
    }
    else if (student_choice == 4)
    {
        view_leaderboard();
    }

    else if (student_choice == 5)
    {
        view_students();
    }
    else if (student_choice == 6)
    {
        exit(1);
    }
}

void half_test()
{
    // to take full mock test,
    char question[500];
    char choice;
    char option1[200], option2[200], option3[200], option4[200];
    int score = 0;
    char correct_answer[200];
    int number_of_questions;

    FILE *fptr;
    FILE *fanswer;
    FILE *user_response;

    fptr = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\set1.txt", "r");
    fanswer = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\set1answer.txt", "r");
    user_response = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\user_response.txt", "w");
    printf("Enter number of questions\n");
    scanf("%d", &number_of_questions);
    if (fptr == NULL)
    {
        printf("The question file does not exist\n");
    }
    if (fanswer == NULL)
    {
        printf("The answer file does not exist \n");
    }

    for (int j = 0; j < number_of_questions; j++)
    {
        printf("\n********************CONSOL BASED IOE ENTRANCE PREPARATION *************************\n\n\n\n\n\n\n\n\n\n");
        fgets(correct_answer, sizeof(correct_answer), fanswer);
        for (int i = 1; i <= 7; i++)
        {
            fgets(question, sizeof(question), fptr); // read data from file

            fflush(stdin);
            if (i == 1)
            {
                printf("\t%s", question); // prints question
                fprintf(user_response, "%s\n\n", question);
            }
            else if (i == 3)
                strcpy(option1, question); // copy option 1

            else if (i == 4)
                strcpy(option2, question); // copy option2

            else if (i == 5)
                strcpy(option3, question); // copy option3

            else if (i == 6)
                strcpy(option4, question); // copy option4

            if (i > 1 && i <= 7)
            {
                printf("\t%s", question); // print content question after and before next question
            }
        }
        answer_checker(correct_answer, option1, option2, option3, option4, &score, user_response); // check option
        system("cls");
    }

    fclose(user_response);
    user_response_print(); // final score

    printf("\t\t CONGRATULATIONS!!!!\n\t\t YOU SCORED: %d\n\n", score);
    fclose(fanswer);
    fclose(fptr);
}

void full_test()
{
    // to take full mock test,
    char question[500];
    char choice;
    char option1[200], option2[200], option3[200], option4[200];
    int score = 0;
    char correct_answer[200];

    FILE *fptr;
    FILE *fanswer;
    FILE *user_response;
    char id_number[20];
    printf("\n\n\n\t!!!!PLEASE ENTER YOU VALID IDENTIFICATION NUMBER!!!!:  "); // for leaderboard
    scanf("%[^\n]%*c", id_number);
    fptr = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\set1.txt", "r");
    fanswer = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\set1answer.txt", "r");
    user_response = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\user_response.txt", "w");

    if (fptr == NULL)
    {
        printf("The question file does not exist\n");
    }
    if (fanswer == NULL)
    {
        printf("The answer file does not exist \n");
    }

    for (int j = 0; j < 100; j++)
    {
        printf("\n********************CONSOL BASED IOE ENTRANCE PREPARATION *************************\n\n\n\n\n\n\n\n\n\n");
        fgets(correct_answer, sizeof(correct_answer), fanswer);
        for (int i = 1; i <= 7; i++)
        {
            fgets(question, sizeof(question), fptr); // read data from file

            fflush(stdin);
            if (i == 1)
            {
                printf("\t%s", question); // prints question
                fprintf(user_response, "%s\n\n", question);
            }
            else if (i == 3)
                strcpy(option1, question); // copy option 1

            else if (i == 4)
                strcpy(option2, question); // copy option2

            else if (i == 5)
                strcpy(option3, question); // copy option3

            else if (i == 6)
                strcpy(option4, question); // copy option4

            if (i > 1 && i <= 7)
            {
                printf("\t%s", question); // print content question after and before next question
            }
        }
        answer_checker(correct_answer, option1, option2, option3, option4, &score, user_response); // check option
        system("cls");
    }

    leader_board(id_number, &score);

    fclose(user_response);
    user_response_print(); // final score
    printf("\t\t CONGRATULATIONS!!!!\n\t\t YOU SCORED: %d\n\n", score);
    fclose(fanswer);
    fclose(fptr);
}

void answer_checker(char *correct_answer, char *option1, char *option2, char *option3, char *option4, int *fscore, FILE *user_response)
{
    fflush(stdin);
    char user_choice;
    char wrong_option[200], correct_option[200];
    printf("\tEnter your option (A or B or C or or D):  ");
    scanf("%c", &user_choice);
    user_choice = toupper(user_choice);
    if (user_choice == correct_answer[0])
    {

        if (user_choice == option1[0])
            fprintf(user_response, "You Entered Correct answer : %s", option1);
        if (user_choice == option2[0])
            fprintf(user_response, "You Entered Correct answer : %s", option2);
        if (user_choice == option3[0])
            fprintf(user_response, "You Entered Correct answer : %s", option3);
        if (user_choice == option4[0])
            fprintf(user_response, "You Entered Correct answer : %s", option4);
        (*fscore)++;
        fprintf(user_response, "\nYou got 1 marks \n\n");
    }
    else
    {

        if (user_choice == option1[0])
            strcpy(wrong_option, option1);
        if (user_choice == option2[0])
            strcpy(wrong_option, option2);
        if (user_choice == option3[0])
            strcpy(wrong_option, option3);
        if (user_choice == option4[0])
            strcpy(wrong_option, option4);

        if (correct_answer[0] == option1[0])
            strcpy(correct_option, option1);
        if (correct_answer[0] == option2[0])
            strcpy(correct_option, option2);
        if (correct_answer[0] == option3[0])
            strcpy(correct_option, option3);
        if (correct_answer[0] == option4[0])
            strcpy(correct_option, option4);

        fprintf(user_response, "You Entered : %s\n", wrong_option);
        fprintf(user_response, "Correct answer is : %s\n", correct_option);
    }
    fprintf(user_response, "__________________________________________\n");
    fprintf(user_response, "__________________________________________\n\n");
}

void user_response_print()
{
    FILE *user_response_print;
    char buffer[500000];
    user_response_print = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\user_response.txt", "r");
    while (fgets(buffer, sizeof(buffer), user_response_print))
    {
        printf("%s", buffer);
    }
    fclose(user_response_print);
    system("pause");
}

void test_cover_display()
{
    printf("\n\n\n\n\n\n");
    printf("\n\t   __________      _________        ________       _____________                 ");
    printf("\n\t       |          |                |                     |                       ");
    printf("\n\t       |          |                |                     |                       ");
    printf("\n\t       |          |                |                     |                       ");
    printf("\n\t       |          |_________       |________             |                       ");
    printf("\n\t       |          |                         |            |                       ");
    printf("\n\t       |          |                         |            |                       ");
    printf("\n\t       |          |_________        ________|            |                       ");
    printf("\n\n\n\n\n\n\t\t\t   PRESS ENTER TO PLAY     ");
    printf("\n\n\n\t\t\t\t   RULES OF THE GAME   :     \n");
    printf("\t\t\t\t   1) 1 MARKS WILL BE AWARDED FOR CORRECT     \n");
    printf("\t\t\t\t   2) NO MARKS WILL AWARDED FOR INCORRECT     \n");
    printf("\t\t\t\t   3) SCORE CARD WILL BE GIVEN AT END         \n");
    system("pause");
    system("cls");
}

// citizenship checker

void student_record()
{
    std_rec student_info;
    FILE *personal_info;
    personal_info = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\final_personal_information.bin", "ab"); // Use "ab" for appending binary mode.

    if (personal_info == NULL)
    {
        printf("PERSONAL INFORMATION FILE DOES NOT EXIST\n");
        return;
    }

    printf("-----------------------------------------------------------\n\n");
    printf("\tEnter your full name: ");
    scanf("%[^\n]%*c", student_info.name);
    fflush(stdin);
    printf("\tEnter your DOB in BS eg-(2060-02-03): ");
    scanf("%[^\n]%*c", student_info.date_of_birth);
    fflush(stdin);

    do
    {
        printf("\tEnter your citizenship number: ");
        scanf("%s", student_info.citizenship_number);
        fflush(stdin);

        if (citizenship_checker(student_info.citizenship_number))
        {
            printf("\tThe citizenship number %s is already taken\n", student_info.citizenship_number);
        }
        else
        {
            break; // Break the loop if the citizenship number is not found in the file.
        }
    } while (1);

    fwrite(&student_info, sizeof(student_info), 1, personal_info);
    fclose(personal_info);
}

// Check citizenship
bool citizenship_checker(const char *citizen_shp)
{
    FILE *personal_info;
    std_rec to_check;
    personal_info = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\final_personal_information.bin", "rb");

    if (personal_info == NULL)
    {
        printf("\tPERSONAL INFORMATION FILE DOES NOT EXIST\n");
        return false;
    }

    while (fread(&to_check, sizeof(to_check), 1, personal_info))
    {
        if (strcmp(to_check.citizenship_number, citizen_shp) == 0)
        {
            fclose(personal_info);
            return true; // Found the citizenship number in the file.
        }
    }

    fclose(personal_info);
    return false; // Citizenship number not found in the file.
}

void display_file()
{
    std_rec to_display;
    FILE *student_personal_information;
    student_personal_information = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\final_personal_information.bin", "rb");
    system("cls");
    // printf("\t\tSTUDENT RECORD\n");
   printf("\t\t _______________________________________________________________________________________\n");
    printf("\t\t|        NAME          |         DOB          |           CITIZENSHIP NUMBER           |\n");
    printf("\t\t|______________________|______________________|________________________________________|\n");



    while (fread(&to_display, sizeof(to_display), 1, student_personal_information))
    {
        printf("\t\t| %-20s | %-20s | %-38s |\n", to_display.name, to_display.date_of_birth, to_display.citizenship_number);
    }

    printf("\t\t________________________________________________________________________________________\n");



    fclose(student_personal_information);
}

void citizenship_id_maker()
{
    int num_of_student;
    int phone_number;
    FILE *user_id;
    user_id = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\user_id.txt", "a");
    if (user_id == NULL)
    {
        printf("User id file doesnot exist");
    }
    FILE *num_of_std;
    num_of_std = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\number_of_students.txt", "r");
    if (num_of_std == NULL)
    {
        printf("number of student file doesnot exist: ");
    }
    fscanf(num_of_std, "%d", &num_of_student);
    printf("\tYour IDENTIFICATION number is IOE079BCT0%d\n", num_of_student);
    printf("\t\t\n\n\tEnter your phone number: ");
    scanf("%d", &phone_number);
    fprintf(user_id, "%d IOE079BCT0%d\n", phone_number, num_of_student);
    fclose(user_id);
    fclose(num_of_std);

    FILE *add_num_of_std;
    add_num_of_std = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\number_of_students.txt", "w");
    if (add_num_of_std == NULL)
    {
        printf("add_ number of student file doesnot exist: ");
    }

    fprintf(add_num_of_std, "%d", num_of_student + 1);
    fclose(add_num_of_std);
}

void id_for_test_checker()
{
    FILE *ptr;
    char buffer[100];
    char d[] = ",";
    char s[50];
    char choice;
    fflush(stdin);
    ptr = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\user_id.txt", "r");
    printf("\tEnter your identification number eg(IOE079BCT...):  ");
    scanf("%[^\n]%*c", s);
    fflush(stdin);
    int flag = 0;
    while (flag != 1)
    {
        fseek(ptr, 0, SEEK_SET);
        while (fgets(buffer, sizeof(buffer), ptr) != NULL)
        {
            if (strstr(buffer, s) != NULL)
            {
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            printf("\n\n\tTHE ID DOES NOT MATCH\n\n");
            printf("\tEnter 'X' OR 'x' to exit from program: else Enter any key to continue except 'x or 'X':  ");
            scanf("%c", &choice);
            fflush(stdin);
            if (choice == 'x' || choice == 'X')
            {
                exit(1);
            }
            
            printf("\tRe-Enter your identification number eg(IOE079BCT...):  ");
            scanf("%[^\n]%*c", s);
            fflush(stdin);
        }
    }

    fclose(ptr);
}

void leader_board(char *id_number, int *score)
{
    int score_form_test = (*score);
    int file_score;
    char id[50];
    FILE *LeaderBoard;
    LeaderBoard = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\leaderboard.txt", "r");
    if (LeaderBoard == NULL)
    {
        printf("leaderboard_file_doesnot exist:");
    }
    fscanf(LeaderBoard, "%s %d", id, &file_score);
    fclose(LeaderBoard);

    FILE *to_write_on_leaderboard;
    to_write_on_leaderboard = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\leaderboard.txt", "w");
    if (to_write_on_leaderboard == NULL)
    {
        printf("Cant write score on leaderboard file");
    }
    if (file_score < score_form_test)
    {
        fprintf(to_write_on_leaderboard, "%s %d", id_number, score_form_test);
    }
    fclose(to_write_on_leaderboard);
}

void view_leaderboard()
{
    int score_to_show;
    char user_id_number[50];
    FILE *ptr;
    ptr = fopen("C:\\Users\\a\\OneDrive\\Desktop\\C FINAL ASSIGNMENT\\question\\leaderboard.txt", "r");
    if (ptr == NULL)
    {
        printf("FAIL to view leader board file");
    }
    fscanf(ptr, "%s %d", user_id_number, &score_to_show);
    printf("\n\n\n\n\n");
    printf("\t\t********HIGHEST MARKS******** \n\n\n");
    printf("\t\t\tID NUMBER: %s\n", user_id_number);
    printf("\t\t\tSCORE: %d", score_to_show);
    printf("\n\n\n\n\n");
    fclose(ptr);
}

void view_students()
{

    
    int i = 0;
    char ch_name, ch_pass;
    char admin[] = "lokendra";
    char admin_name[10];
    char admin_password[20];
    char password[] = "funky";

    printf("Enter admin name: ");
    while ((ch_name = _getch()) != '\r')
    {
        if (ch_name == 8 && i > 0)
        { // Backspace
            printf("\b \b");
            i--;
        }
        else
        {
            admin_name[i] = ch_name;
            i++;
            printf("*");
        }
    }
    admin_name[i] = '\0';
    i = 0;

    printf("\nEnter password: ");
    while ((ch_pass = _getch()) != '\r')
    {
        if (ch_pass == 8 && i > 0)
        { // Backspace
            printf("\b \b");
            i--;
        }
        else
        {
            admin_password[i] = ch_pass;
            i++;
            printf("*");
        }
    }
    admin_password[i] = '\0';

    if ((strcmp(admin, admin_name) == 0) && (strcmp(password, admin_password) == 0))
    {
        
        printf("/n/n");
        display_file();
    }
    else
    {
        printf("\nInvalid admin name or password. Access denied.\n");
    }
    system("pause");
}

bool password_checker(){
     int i = 0;
    char ch_name, ch_pass;
    char admin[] = "lokendra";
    char admin_name[10];
    char admin_password[20];
    char password[] = "funky";

    printf("Enter admin name: ");
    while ((ch_name = _getch()) != '\r')
    {
        if (ch_name == 8 && i > 0)
        { // Backspace
            printf("\b \b");
            i--;
        }
        else
        {
            admin_name[i] = ch_name;
            i++;
            printf("*");
        }
    }
    admin_name[i] = '\0';
    i = 0;

    printf("\nEnter password: ");
    while ((ch_pass = _getch()) != '\r')
    {
        if (ch_pass == 8 && i > 0)
        { // Backspace
            printf("\b \b");
            i--;
        }
        else
        {
            admin_password[i] = ch_pass;
            i++;
            printf("*");
        }
    }
    admin_password[i] = '\0';
       if ((strcmp(admin, admin_name) == 0) && (strcmp(password, admin_password) == 0))
    {
        
        return true;
    }
    else{
        return false;
    }

}
