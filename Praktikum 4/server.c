#ifndef _SERVER_H
#define _SERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256
#define MAX_BODY 512

/**
 * @brief Buka file bernama request.txt kemudian eksekusi. Output berupa file response.txt
 * 
 */
void solution() {
    char line[MAX_LINE];
    char method[MAX_LINE] = "";
    char path[MAX_LINE] = "";
    char content_type[MAX_LINE] = "N/A";
    char body[MAX_BODY] = "";
    char filenimons[20] = "request.txt";
    int body_found = 0;
    
    // Buka file request
    FILE *request_file = fopen(filenimons, "r");
    if (request_file == NULL) {
        printf("Error: Tidak dapat membuka file request.txt\n");
        return;
    }
    
    // Baca baris pertama untuk mendapatkan method dan path
    if (fgets(line, MAX_LINE, request_file) != NULL) {
        sscanf(line, "%s %s", method, path);
    }
    
    // Baca header-header
    while (fgets(line, MAX_LINE, request_file) != NULL) {
        // Jika menemukan baris kosong, berarti selanjutnya adalah body
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0) {
            body_found = 1;
            break;
        }
        
        // Cek apakah header adalah Content-Type
        if (strncmp(line, "Content-Type:", 13) == 0 || strncmp(line, "Content-Type: ", 14) == 0) {
            // Hilangkan "Content-Type: " dari header
            char *start = strstr(line, "Content-Type:");
            start += 13; // Panjang "Content-Type:"
            
            // Lewati spasi di awal jika ada
            while (*start == ' ') {
                start++;
            }
            
            // Salin nilai content type dan hapus newline jika ada
            strcpy(content_type, start);
            char *newline = strchr(content_type, '\n');
            if (newline) {
                *newline = '\0';
            }
            newline = strchr(content_type, '\r');
            if (newline) {
                *newline = '\0';
            }
        }
    }
    
    // Baca body jika ada (perbaikan)
    if (body_found) {
        // Reset body string
        body[0] = '\0';
        
        // Baca semua sisa file sebagai body
        char buffer[MAX_LINE];
        while (fgets(buffer, MAX_LINE, request_file) != NULL) {
            // Tambahkan konten ke body
            strcat(body, buffer);
        }
        
        // Hapus trailing newline dari body jika ada
        size_t len = strlen(body);
        if (len > 0 && (body[len-1] == '\n' || body[len-1] == '\r')) {
            body[len-1] = '\0';
            // Periksa CR+LF
            if (len > 1 && body[len-2] == '\r') {
                body[len-2] = '\0';
            }
        }
    }
    
    fclose(request_file);
    
    // Tulis respons ke file response.txt
    FILE *response_file = fopen("response.txt", "w");
    if (response_file == NULL) {
        printf("Error: Tidak dapat membuka file response.txt\n");
        return;
    }
    
    fprintf(response_file, "HTTP/1.1 200 OK\n");
    fprintf(response_file, "Content-Type: text/plain\n");
    fprintf(response_file, "\n");
    fprintf(response_file, "Method: %s\n", method);
    fprintf(response_file, "Path: %s\n", path);
    fprintf(response_file, "Content-Type: %s\n", content_type);
    
    if (strlen(body) > 0) {
        fprintf(response_file, "Body: %s\n", body);
    }
    
    fclose(response_file);
}

#endif
