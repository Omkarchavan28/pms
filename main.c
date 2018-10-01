                        /*           A PROJECT ON PATIENT MANAGEMENT SYSTEM   */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

                          /* DECLARATION OF variable TO BE USED */

                          char main_exit;
int UID_counter;
int t=0;


                        /* DECLARATION OF FUNCTIONS TO BE USED */

void menu();
int UID_genretor();
void new_patient();
int cal_age(int current_date, int current_month, int current_year, int birth_date, int birth_month, int birth_year);
void new_v_detail();
void existing_patient();
void update();
void get_appointment();
void view_detail();
void view_detailAll();
void close();

                        /* DECLARATION OF STRUCTURES TO BE USED */

                        struct date {
                          int month, day, year;

                        }today;

                        struct patient {
                          char name[40];
                         char pname[40];
                          char gender[10];
                          int UID;
                          int age;
                          double phone;
                          char disease[60];
                          char doc_name[40];
                          char address[60];
                          struct date dob;
                          struct date v_date;
                          struct date appoinment;
                        }add,upd,check,app,rec;

                        /* MAIN MENU FUNCTION */
                        int main() {
                          menu();
                          return 0;
                        }







                        void menu() {

                             system("cls");

                          printf("\t\t***************************************************");
                          printf("\n\t\t  **** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ****");
                          printf("\n\t\t*************************************************");
                          //printf("\n\t\t\t\t--Made by Omkar Chavan");
                          A:
                            printf("\n\n\n");
                          printf("\n\t\t1. Existing Patient Options");
                          printf("\n\t\t2. To Enter New Patient to Records ");
                          printf("\n\t\t0. Exit");
                          printf("\n\n\tEnter your choice: ");
                          fflush(stdin);
                          main_exit = getche();
                            system("cls");
                          switch (main_exit) {
                          case '1':if(t==0){
                              t=1;
                                printf("\n\n\nEnter today's date(dd/mm/yyyy):");
                          scanf("%d/%d/%d", & today.day, & today.month, & today.year);
                          }
                                  system("cls");
                            existing_patient();
                            break;
                          case '2':if(t==0) {
                              t=1;
                                printf("\n\n\nEnter today's date(dd/mm/yyyy):");
                          scanf("%d/%d/%d", & today.day, & today.month, & today.year);
                          }
                                  system("cls");
                            new_patient();
                            break;

                          case '0':
                           // close();
                            break;
                          default:

                            printf("wrong choice");
                            goto A;
                          }

                        }



        void existing_patient() {
            int t=0;
                               add_invalid:
                           if (t == 1) {

                            printf("Invalid option!");
                              }


                                printf("\n\n\t\t\t PATIENT");
                                printf("\n\t\t1.Update Existing Record");
                                printf("\n\t\t2.Get an Appointment");
                                printf("\n\t\t3.Enter details of new visit");
                                printf("\n\t\t4.Check the details of existing account");
                                printf("\n\t\t5.View Patient list");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                fflush(stdin);
                                main_exit = getche();
                                switch (main_exit) {
                                case '1':system("cls");
                                       update();
                                        break;
                                case '2':system("cls");
                                       get_appointment();
                                        break;
                                case '3':system("cls");
                                        new_v_detail();
                                        break;
                                case '4':system("cls");
                                        view_detail();
                                        break;
                                case '5':system("cls");
                                        view_detailAll();
                                        break;
                                case '6':system("cls");

                                        menu();
                                        break;
                                case '0':
                                        close();
                                        break;
                                default: t=1;
                                        system("cls");

                                        goto add_invalid;

                                }
        }




   void new_patient() {


                          FILE * ptr,*ptr2;
                          ptr = fopen("Patients/patient.DAT", "a+");
                          ptr2 = fopen("Records/record.DAT", "a+");

                          printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");


                          rec.v_date.day=add.v_date.day=today.day;
                          rec.v_date.month=add.v_date.month=today.month;
                          rec.v_date.year=add.v_date.year=today.year;

                          rec.UID=add.UID=UID_genretor();

                          printf("Your UID is '%d'(Remember his for after use)",add.UID);

                       printf("\nEnter the name:");
                          scanf("%s", add.name);
                          printf("\nEnter the name of Father/Mother/Gaurdian:");
                          scanf("%s", add.pname);

                          printf("\nEnter the date of birth(dd/mm/yyyy):");
                          scanf("%d/%d/%d", & add.dob.day, & add.dob.month, & add.dob.year);
                        rec.age=add.age = cal_age(add.v_date.day, add.v_date.month, add.v_date.year, add.dob.day, add.dob.month, add.dob.year);
                          printf("\nEnter the Gender[Male/Female/Other]:");
                          scanf("%s", add.gender);
                          printf("\nEnter the address:");
                         scanf("%s", add.address);
                          printf("\nEnter the phone number: ");
                          scanf("%lf", &add.phone);
                          printf("\nEnter the Disease:");
                          scanf("%s", add.disease);
                          strcpy(rec.disease,add.disease);
                          printf("\nEnter the Doctor's Name:");
                          scanf("%s", add.doc_name);
                          add.appoinment.day = 00;
                          add.appoinment.month = 00;
                          add.appoinment.year = 00;


                          fprintf(ptr,"%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, add.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day,add.appoinment.month, add.appoinment.year);
                          fprintf(ptr2,"%d %d/%d/%d %d %s\n",rec.UID,rec.v_date.day, rec.v_date.month, rec.v_date.year,rec.age,rec.disease);

                          fclose(ptr2);
                          fclose(ptr);
                          printf("\nPatient added successfully!");
                          add_invalid:
                          printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                          fflush(stdin);
                          main_exit = getche();


                          if (main_exit == '1')
                          {  system("cls");
                            menu();
                          }
                          else if (main_exit == '0')
                            close();
                          else {system("cls");
                            printf("\nInvalid!\a");
                            goto add_invalid;
                          }

                        }






void update()
{
    char choice;
    int test=0;
    FILE *old,*newrec;
    old=fopen("Patients/patient.DAT","r");
    newrec=fopen("Patients/update.DAT","w");

    printf("\nEnter the UID of patient whose info you want to change:");
    scanf("%d",&upd.UID);
    system("cls");
    while(fscanf(old, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, & add.UID, add.gender, &add.phone, & add.age, add.address, add.disease, add.doc_name, & add.dob.day, & add.dob.month, & add.dob.year, & add.v_date.day, & add.v_date.month, & add.v_date.year, & add.appoinment.day, & add.appoinment.month, & add.appoinment.year)!=EOF)
    {
        if (add.UID==upd.UID)
        {   test=1;

                          add.v_date.day=today.day;
                          add.v_date.month=today.month;
                          add.v_date.year=today.year;

           add.age = cal_age(add.v_date.day, add.v_date.month, add.v_date.year, add.dob.day, add.dob.month, add.dob.year);
A:
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");

            fflush(stdin);
             choice=getche();

            if(choice=='1')
                {printf("\nEnter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, add.phone, add.age, upd.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice=='2')
                {
                    printf("\nEnter the new phone number:");
                scanf("%lf",& upd.phone);
                fprintf(newrec, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, upd.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);
                printf("\nChanges saved!");
                }

        }
        else
        fprintf(newrec, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, add.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);

         printf("\n1.update another record?\n2.done\nenter your choice:");
         fflush(stdin);
         choice=getche();
         if(choice=='1')
            goto A;
         else
            break;
    }fclose(newrec);
    fclose(old);

    remove("Patients/patient.DAT");
    rename("Patients/update.DAT","Patients/patient.DAT");

if(test!=1)
        {
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              fflush(stdin);
              main_exit=getche();

                 if (main_exit=='1'){
system("cls");
                    menu();
                 }
                else if (main_exit=='2')
                    close();
                else if(main_exit=='0'){
                    update();
                }
                else
                    {system("cls");
                    printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        { system("cls");
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");

        fflush(stdin);
  main_exit=getche();
        if (main_exit=='1')
            menu();
        else
            close();
        }
}













void view_detail()
{
    FILE *ptr,*ptr2;
    int test=0;


    ptr=fopen("Patients/patient.DAT","r");
     ptr2 = fopen("Records/record.DAT", "r");
    printf("\n\n Enter the UID of patient you want to View :");

    system("cls");
    printf("\nEnter the UID:");
        scanf("%d",&check.UID);

        while (fscanf(ptr,"%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n",add.name,add.pname,&add.UID,add.gender,&add.phone,&add.age,add.address,add.disease,add.doc_name,&add.dob.day,&add.dob.month,&add.dob.year,&add.v_date.day,&add.v_date.month,&add.v_date.year,&add.appoinment.day,&add.appoinment.month,&add.appoinment.year)!=EOF)
        {

            if(add.UID==check.UID)
            {
                  while(fscanf(ptr2,"%d %d/%d/%d %d %s\n",&rec.UID,&rec.v_date.day, &rec.v_date.month, &rec.v_date.year,&rec.age,rec.disease)!=EOF)
        {
                      if(rec.UID==check.UID)
                {
                test=1;
                printf("\n\tUID\tNAME\tParents\tname\tgender\tPHONE\tAGE\t\t\tADDRESS\t\t\t\t\tDisease\t\t\tDOC NAME\tDOB\tLAst vDate\tAppoitenmet vDate\n");
 printf("\n%d %s %s %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n\n", add.UID, add.name,add.pname, add.gender, add.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);
                printf("\n%d %d/%d/%d %d %s\n",rec.UID,rec.v_date.day, rec.v_date.month, rec.v_date.year,rec.age,rec.disease);
                 }
        }

            }


        }


fclose(ptr2);
    fclose(ptr);
     if(test!=1)
        {    system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                fflush(stdin);
                main_exit=getche();

                 if (main_exit=='1')
                    menu();
                else if (main_exit=='2')
                    close();
                else if(main_exit=='0')
                    view_detail();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {
        view_invalid:
        printf("\n\nEnter 1 to view other patient,2 to go to the main menu and 0 to exit:");
         fflush(stdin);
        main_exit = getche();

        if (main_exit=='1'){
            system("cls");
           view_detail();
        }
        else if(main_exit=='2')
             menu();
        else if(main_exit=='0')
            close();
        else
        {    system("cls");
            printf("\nInvalid!\a");
            goto view_invalid;
        }
            }
}



void view_detailAll(){


    FILE *view,*ptr;
    view=fopen("Patients/patient.DAT","r");
    ptr=fopen("Records/record.DAT","r");
    int test=0;

    //printf("\nUID. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, & add.UID, add.gender,  &add.phone, & add.age, add.address, add.disease, add.doc_name, & add.dob.day, & add.dob.month, & add.dob.year, & add.v_date.day, & add.v_date.month, & add.v_date.year, & add.appoinment.day, & add.appoinment.month, & add.appoinment.year)&&fscanf(ptr,"%d %d/%d/%d %d %s\n",&rec.UID,&rec.v_date.day, &rec.v_date.month, &rec.v_date.year,&rec.age,rec.disease)!=EOF)
       {
                printf("\nUID\tNAME\tParents\tname\tgender\tPHONE\tAGE\t\tADDRESS\t\t\tDisease\t\tDOC NAME\tDOB\tLAst vDate\tAppoitenmet vDate\n");

           printf( "\n%d\t%s\t%s\t%s\t%lf\t%d\t\t%s\t\t%s\t\t%s\t%d/%d/%d\t%d/%d/%d\t%d/%d/%d\n", add.UID, add.name,add.pname, add.gender, add.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);
           printf("\n%d %d/%d/%d %d %s\n",rec.UID,rec.v_date.day, rec.v_date.month, rec.v_date.year,rec.age,rec.disease);
           printf("***************************************************************************************************");
           test++;
       }

    fclose(ptr);
    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
         fflush(stdin);
        main_exit = getche();

        if (main_exit=='1')
            menu();
        else if(main_exit=='0')
            close();
        else
        {   system("cls");
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }





                       }


void get_appointment(){

    int test=0;
    FILE *old,*newrec;
    old=fopen("Patients/patient.DAT","r");
    newrec=fopen("Patients/update.DAT","w");
    printf("\nEnter the UID of patient :");
    scanf("%d",&app.UID);
while(fscanf(old, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, & add.UID, add.gender,&add.phone, & add.age, add.address, add.disease, add.doc_name, & add.dob.day, & add.dob.month, & add.dob.year, & add.v_date.day, & add.v_date.month, & add.v_date.year, & add.appoinment.day, & add.appoinment.month, & add.appoinment.year)!=EOF)
    {
        if (add.UID==app.UID)
        {   test=1;

                          add.v_date.day=today.day;
                          add.v_date.month=today.month;
                          add.v_date.year=today.year;

           app.appoinment.day=(rand()%30+1);
           app.appoinment.month=((rand()%12)+1);
           app.appoinment.year=(add.v_date.year);
           printf("\nYour appointment is set on date %d/%d/%d",app.appoinment.day,app.appoinment.month,app.appoinment.year);
             fprintf(newrec, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, upd.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, app.appoinment.day, app.appoinment.month, app.appoinment.year);


        }
        else
              fprintf(newrec, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, add.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);


    }
    fclose(old);
    fclose(newrec);
    remove("Patients/patient.DAT");
    rename("Patients/update.DAT","Patients/patient.DAT");

if(test!=1)
        {
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              fflush(stdin);
              main_exit=getche();

                 if (main_exit=='1')

                    menu();
                else if (main_exit=='2')
                    close();
                else if(main_exit=='0')
                    update();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");

        fflush(stdin);
  main_exit=getche();
        if (main_exit=='1')
            menu();
        else
            close();
        }
}



void new_v_detail()
{      int test=0;
       FILE *oldp,*newp,*oldr,*newr;
                          oldp = fopen("Patients/patient.DAT", "r");
                          oldr = fopen("Records/record.DAT", "r");
                          newp = fopen("Patients/update_pat.DAT", "w");
                          newr = fopen("Records/update_rec.DAT", "w");

                          rec.v_date.day=add.v_date.day=today.day;
                          rec.v_date.month=add.v_date.month=today.month;
                          rec.v_date.year=add.v_date.year=today.year;

   // char choice;

    printf("\n\nEnter UID to Enter new visit detail:");
    scanf("%d",&check.UID);

        while (fscanf(oldp,"%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n",add.name,add.pname,&add.UID,add.gender,&add.phone,&add.age,add.address,add.disease,add.doc_name,&add.dob.day,&add.dob.month,&add.dob.year,&add.v_date.day,&add.v_date.month,&add.v_date.year,&add.appoinment.day,&add.appoinment.month,&add.appoinment.year)!=EOF)
        {
            while(fscanf(oldr,"%d %d/%d/%d %d %s\n",&rec.UID,&rec.v_date.day, &rec.v_date.month, &rec.v_date.year,&rec.age,rec.disease)!=EOF)
        {
            if(add.UID==check.UID)
            { if(rec.UID==check.UID)
                {
                           test=1;

                          add.v_date.day=today.day;
                          add.v_date.month=today.month;
                          add.v_date.year=today.year;

           upd.age = cal_age(add.v_date.day, add.v_date.month, add.v_date.year, add.dob.day, add.dob.month, add.dob.year);

           printf("\nEnter the new Visiting date(dd/mm/yyyy):");
           scanf("%d/%d/%d", & upd.v_date.day, & upd.v_date.month, &upd.v_date.year );

                printf("\nEnter Disease discription:");
                scanf("%s", upd.disease);
                fprintf(newp, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name, add.pname, add.UID, add.gender, add.phone, upd.age, upd.address, upd.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, upd.v_date.day, upd.v_date.month, upd.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);
                fprintf(newr,"\n%d %d/%d/%d %d %s\n",rec.UID,upd.v_date.day, upd.v_date.month, upd.v_date.year,upd.age,upd.disease);

                printf("\nDetails saved!\n");


        }
        else{
        fprintf(newp, "%s %s %d %s %lf %d %s %s %s %d/%d/%d %d/%d/%d %d/%d/%d\n", add.name,add.pname, add.UID, add.gender, add.phone, add.age, add.address, add.disease, add.doc_name, add.dob.day, add.dob.month, add.dob.year, add.v_date.day, add.v_date.month, add.v_date.year, add.appoinment.day, add.appoinment.month, add.appoinment.year);
        fprintf(newr,"\n%d %d/%d/%d %d %s\n",rec.UID,rec.v_date.day, rec.v_date.month, rec.v_date.year,rec.age,rec.disease);
         }





       }
     }
   }

    fclose(newr);
    fclose(newp);
    fclose(oldr);
    fclose(oldp);
    remove("Patients/patient.DAT");
    rename("Patients/update_pat.DAT","Patients/patient.DAT");
    remove("Records/record.DAT");
    rename("Records/update_rec.DAT","Records/record.DAT");

    if(test!=1)
        {    system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              fflush(stdin);
              main_exit=getche();

                 if (main_exit=='1')

                    menu();
                else if (main_exit=='2')
                    close();
                else if(main_exit=='0')
                    update();
                else
                    {system("cls");
                    printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");

        fflush(stdin);
  main_exit=getche();
        if (main_exit=='1')
            menu();
        else
            close();
        }

}

                        int cal_age(int current_date, int current_month, int current_year, int birth_date, int birth_month, int birth_year) {

                          if (birth_date > current_date) {
                            current_month = current_month - 1;
                            current_date = current_date + 30;
                          }
                          if (birth_month > current_month) {
                            current_year = current_year - 1;
                            current_month = current_month + 12;
                          }
                          if (birth_year > current_year) {
                            printf("birth year cant be more than current year!!!!");

                          }
                          //int calculated_date = current_date - birth_date;
                          // int calculated_month = current_month - birth_month;
                          int calculated_year = current_year - birth_year;
                          return calculated_year;

                        }



int UID_genretor(){

FILE *counter;

 counter = fopen("Patients/Counter.DAT", "r+");
 if(counter==NULL){
     counter = fopen("Patients/Counter.DAT", "w");
     UID_counter=0;
    fprintf(counter,"%d",UID_counter);
    fclose(counter);
    return UID_counter;
 }
 else{
    fscanf(counter,"%d",&UID_counter);
    UID_counter++;
    counter= fopen("Patients/Counter.DAT", "w");
    fprintf(counter,"%d",UID_counter);
    fclose(counter);
return UID_counter;
 }
}



                        void close(void) {

                          printf("\n\n\n\nThis C Mini Project is developed by Code With C team!");
                        }



