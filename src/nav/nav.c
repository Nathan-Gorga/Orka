#include "nav.h"



folderContent * createFolderContent(){
    folderContent * content = (folderContent*)malloc(sizeof(folderContent));
    content->next = NULL;
    return content;
}

void listFolderContents(const char const* folderpath){
    folderContent * head = createFolderContent();

    getFolderContents(folderpath, head);

    folderContent * curr = head;
    folderContent * prev = NULL;   
    while(curr != NULL){

        if (curr->content.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) printf(YELLOW);
        printf("%s  ", curr->content.cFileName);
        prev = curr;
        curr = curr->next;
        free(prev);

        printf(RESET);
    }    
}


void getFolderContents(const char const* folderpath, folderContent * head){
    

    folderContent * curr = head;
    curr->next = NULL;

    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    
    // Build search pattern like: "C:\\path\\to\\folder\\*"
    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", folderpath);

    hFind = FindFirstFile(searchPath, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("No files found in %s\n", folderpath);
        head = NULL;
        return;
    }

    
    do {
        const char *name = findFileData.cFileName;

        // Skip "." and ".."
        if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
            
            curr->content = findFileData;
            curr->next = createFolderContent();
            curr = curr->next; 
            
        }
    } while (FindNextFile(hFind, &findFileData));

    FindClose(hFind);
}

void help_nav(void){
    //typing the name of the folder to navigate into it
    //.. to move back one folder
    //# to move back to the root codebase

    printf("\n\n\t ~~ navigation commands ~~\n");

    printf("("RED"type name"RESET") : select folder | ");
    printf("("RED".."RESET") move back | ");
    printf("("RED"#"RESET") move back to codebase folder\n");
    
}

void start_nav(const char const* codebase_location){
    
    printf("starting navigation in %s\n", codebase_location);
    printf("\n"CYAN"%s : \n"RESET, codebase_location);
    printf("\t");
    listFolderContents(codebase_location);

    help_nav();


}