#include "master.h"

#define BUF_SIZE 4096

// Generate output file name
void generate_output_filename(char *out, const char *input_name, char mode) {
    if (mode == 'e') {
        sprintf(out, "#enc_%s", input_name);
    } else {
        sprintf(out, "#denc%s", input_name);  // do NOT strip #enc_ prefix
    }
}

// Read entire file into memory
unsigned char* read_file(const char *filename, size_t *size) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");

        // Print current working directory
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd))) {
            fprintf(stderr, "Current working directory: %s\n", cwd);
        } else {
            perror("getcwd");
        }

        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    rewind(f);

    unsigned char *data = malloc(fsize);
    if (!data) {
        fclose(f);
        return NULL;
    }

    fread(data, 1, fsize, f);
    fclose(f);
    *size = fsize;
    return data;
}

// Write buffer to file
int write_file(const char *filename, const char *data, size_t len) {
    FILE *f = fopen(filename, "wb");
    if (!f) return 0;
    fwrite(data, 1, len, f);
    fclose(f);
    return 1;
}
int main() {
    char mode;
    char filename[256];

    printf("Enter mode (e for encode, d for decode): ");
    if (scanf(" %c", &mode) != 1 || (mode != 'e' && mode != 'd')) {
        fprintf(stderr, "Invalid mode.\n");
        return 1;
    }

    printf("Enter file name: ");
    if (scanf(" %255s", filename) != 1) {
        fprintf(stderr, "Invalid file name.\n");
        return 1;
    }

    size_t input_len, output_len;
    char *output_data = NULL;
    unsigned char *input_data = NULL;

    input_data = read_file(filename, &input_len);
    if (!input_data) {
        fprintf(stderr, "Failed to read file: %s\n", filename);
        return 1;
    }

    if (mode == 'e') {
        output_data = base64_encode(input_data, input_len, &output_len);
    } else {
        output_data = base64_decode((const char *)input_data, input_len, &output_len);
    }

    free(input_data);

    if (!output_data) {
        fprintf(stderr, "Failed to %s data.\n", mode == 'e' ? "encode" : "decode");
        return 1;
    }

    char output_filename[512];
    generate_output_filename(output_filename, filename, mode);

    if (!write_file(output_filename, output_data, output_len)) {
        fprintf(stderr, "Failed to write to file: %s\n", output_filename);
        free(output_data);
        return 1;
    }

    printf("Output written to %s\n", output_filename);
    free(output_data);
    return 0;
}
