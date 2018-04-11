#include "checker.h"

#include <curl/curl.h>
#include <string>

Checker::Checker(char *url) { this->url = url; }

Checker::~Checker() {}

size_t writeCallback(char *content, size_t size, size_t nmemb, void *userdata) {
  // Append the content to user data
  ((std::string *)userdata)->append(content, size * nmemb);

  // Return the real content size
  return size * nmemb;
}

bool Checker::checkAccount(Account *account) {
  // Set crendentials
  std::string credentials = std::string(account->getUsername()) + ":" +
                            std::string(account->getPassword());

  // Init curl, response and status code buffers
  CURL *curl = curl_easy_init();
  std::string responseBuffer;
  long statusCode = 0;

  if (curl) {
    // Set login url
    curl_easy_setopt(curl, CURLOPT_URL, this->url);

    // Specify the POST data
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
    curl_easy_setopt(curl, CURLOPT_USERPWD, credentials.c_str());

    // Write result into the buffer
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

    // Perform the request, res will get the return code
    CURLcode res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    
    // Get HTTP status code
    curl_easy_getinfo(curl, CURLINFO_HTTP_CODE, &statusCode);

    // Always cleanup
    curl_easy_cleanup(curl);
  }

  // Check status code and return result
  if (statusCode == 200) {
    return true;
  } else {
    return false;
  }
}