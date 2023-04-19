/*Develop a program that reads and stores information about movies using a structure. program should allow user to search for movies based onir genre, release year, and rating, and display details of matching movies using pointers.*/

#include <stdio.h>
#include <string.h>
//movie structure
struct Movie {
    char title[100];
    char genre[50];
    int year;
    float rating;
};
int main() {
    int numMovies;
    printf("Enter number of movies: ");
    scanf("%d", &numMovies);

    struct Movie* movies = (struct Movie*) malloc(numMovies * sizeof(struct Movie));
    // input from user
    for (int i = 0; i < numMovies; i++) {
        printf("Enter title of movie %d: ", i + 1);
        scanf(" %[^\n]", movies[i].title);
        printf("Enter genre of movie %d: ", i + 1);
        scanf(" %[^\n]", movies[i].genre);
        printf("Enter release year of movie %d: ", i + 1);
        scanf("%d", &movies[i].year);
        printf("Enter rating of movie %d: ", i + 1);
        scanf("%f", &movies[i].rating);
    }

    char searchGenre[50];
    int searchYear;
    float searchRating;
    printf("\nEnter genre to search for: ");
    scanf(" %[^\n]", searchGenre);
    printf("Enter release year to search for: ");
    scanf("%d", &searchYear);
    printf("Enter rating to search for: ");
    scanf("%f", &searchRating);
    printf("\nMatching Movies:\n");
    int matchFound = 0;
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0 &&
            movies[i].year == searchYear &&
            movies[i].rating == searchRating) {
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Release Year: %d\n", movies[i].year);
            printf("Rating: %.2f\n", movies[i].rating);
            printf("--------------------------\n");
            matchFound = 1;
        }
    }
    if (!matchFound) {
        printf("No matching movies found.\n");
    }
    free(movies);

    return 0;
}
