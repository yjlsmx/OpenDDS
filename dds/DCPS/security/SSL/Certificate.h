/*
 * Distributed under the DDS License.
 * See: http://www.DDS.org/license.html
 */

#ifndef OPENDDS_SECURITY_SSL_CERTIFICATE_H
#define OPENDDS_SECURITY_SSL_CERTIFICATE_H

#include <string>
#include <iostream>
#include <openssl/x509.h>

namespace OpenDDS {
  namespace Security {
    namespace SSL {

      class Certificate
      {
      public:
        Certificate(const std::string& uri, const std::string& password = "");

        Certificate();

        ~Certificate();

        Certificate& operator=(const Certificate& rhs);

        void load(const std::string& uri, const std::string& password = "");

        X509* get()
        {
          return x_;
        }

        int validate(Certificate& ca, unsigned long int flags = 0u);

      private:

        static X509* x509_from_pem(const std::string& path, const std::string& password = "");

        X509* x_;
      };

      std::ostream& operator<<(std::ostream& lhs, Certificate& rhs);
    }
  }
}

#endif
