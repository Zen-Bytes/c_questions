//Develop a program that reads and stores information about movies using a structure. The program should allow the user to search for movies based on their genre, release year, and rating, and display the details of matching movies using pointers.

#include <stdio.h>
#include <string.h>

// Structure to store movie information
struct Movie {
    char title[100];
    char genre[50];
    int releaseYear;
    float rating;
};

int main() {
    int numMovies;
    printf("Enter the number of movies: ");
    scanf("%d", &numMovies);

    // Dynamically allocate memory for an array of movies
    struct Movie* movies = (struct Movie*) malloc(numMovies * sizeof(struct Movie));

    // Read movie information from user
    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i + 1);
        scanf(" %[^\n]", movies[i].title);
        printf("Enter the genre of movie %d: ", i + 1);
        scanf(" %[^\n]", movies[i].genre);
        printf("Enter the release year of movie %d: ", i + 1);
        scanf("%d", &movies[i].releaseYear);
        printf("Enter the rating of movie %d: ", i + 1);
        scanf("%f", &movies[i].rating);
    }

    // Search movies based on user input
    char searchGenre[50];
    int searchYear;
    float searchRating;
    printf("\nEnter the genre to search for: ");
    scanf(" %[^\n]", searchGenre);
    printf("Enter the release year to search for: ");
    scanf("%d", &searchYear);
    printf("Enter the rating to search for: ");
    scanf("%f", &searchRating);

    printf("\nMatching Movies:\n");
    int matchFound = 0;
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0 &&
            movies[i].releaseYear == searchYear &&
            movies[i].rating == searchRating) {
            printf("Title: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.2f\n", movies[i].rating);
            printf("--------------------------\n");
            matchFound = 1;
        }
    }

    if (!matchFound) {
        printf("No matching movies found.\n");
    }

    // Free dynamically allocated memory
    free(movies);

    return 0;
}
