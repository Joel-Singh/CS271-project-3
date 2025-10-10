#include "cryptlib.h"
#include "files.h"
#include "hex.h"
#include "sha3.h"
#include <stdlib.h>
#include <string>

#ifndef ENCRYPTION_JOEL // Use my name because cryptopp alread uses an
                        // ENCRYPTION macro variable
#define ENCRYPTION_JOEL

using namespace std;
using namespace CryptoPP;

//=================================================
// encrypt
// Returns a digest hex string made from `plain_text` using SHA3_256.
//
// PARAMETERS:
//  plain_text: The text being encrypted
//
// RETURN VALUE:
//  A digest
//=================================================
string encrypt(string plain_text) {

  // followed the second example from https://www.cryptopp.com/wiki/SHA3 to
  // encrypt
  SHA3_256 hash;
  string digest;
  hash.Update((const CryptoPP::byte *)plain_text.data(), plain_text.size());
  digest.resize(hash.DigestSize());
  hash.Final((CryptoPP::byte *)&digest[0]);

  string digest_str;
  CryptoPP::StringSource(
      digest, true,
      new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest_str)));

  return digest_str;
}

//=================================================
// truncate_digest_to_int
// truncate `digest` to an int
//
// PARAMETERS:
//  digest: The digest to truncate
//
// RETURN VALUE:
//  Int representing the truncated digest
//=================================================
int truncate_digest_to_int(string &digest) {
  return stoi(digest.substr(0, 7), nullptr, 16);
}

#endif
