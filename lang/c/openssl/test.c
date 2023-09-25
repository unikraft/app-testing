#include <stdio.h>
#include <openssl/crypto.h>

int main(void) {
    printf("%s", OpenSSL_version(OPENSSL_VERSION));
    return 0;
}
