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


void start_nav(const char const* codebase_location){
    
}