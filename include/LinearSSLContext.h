#import <Foundation/Foundation.h>

#pragma mark - SSLContext

/** SSL Method Definitions */
typedef NS_ENUM(NSInteger, LinearSSLMethod) {
  /** OpenSSL::SSLv23_method */
  LinearSSLv23,
  /** OpenSSL::TLSv1_1_method */
  LinearSSLTLSv1_1,
};

/** SSL Verify Mode Definitions */
typedef NS_ENUM(NSInteger, LinearSSLVerifyMode) {
  /** OpenSSL::SSL_VERIFY_NONE */
  LinearSSLVerifyNone,
  /** OpenSSL::SSLVERIFY_PEER | OPENSSL_VERIFY_CLIENT_ONCE */
  LinearSSLVerifyPeer,
};

/**
 * SSLContext class
 */
@interface LinearSSLContext : NSObject

/**
   LinearSSLMethod

   Default: LinearSSLv23
 */
@property (nonatomic, assign) LinearSSLMethod method;
/**
   LinearSSLVerifyMode

   Default: LinearSSLVerifyPeer
*/
@property (nonatomic, assign) LinearSSLVerifyMode mode;
/**
   @brief self certificate.
   Set path of certificate file like below.

   ```
    ctx.cert = [[NSBundle mainBundle] pathForResource: @"certificate" ofType:@"pem"];
   ```

   @note both PEM and DER are acceptable, and stay nil if there's no need.
 */
@property (nonatomic, copy) NSString *cert;
/**
   @brief private key for self certificate.

   set path of private key file like below.

   ```
    ctx.pkey = [[NSBundle mainBundle] pathForResource: @"private" ofType:@"key"];
   ```

   @note both PEM and DER are acceptable, and stay nil if there's no need.
 */
@property (nonatomic, copy) NSString *pkey;
/**
 * passphrase for private key if needed.
 */
@property (nonatomic, copy) NSString *pass;
/**
   @brief cipher suites string

   ex.(default value)

   ```
    ctx.cipher = @"ALL:EECDH+HIGH:EDH+HIGH:+MEDIUM+HIGH:!EXP:!LOW:!eNULL:!aNULL:!MD5:!RC4:!ADH:!KRB5:!PSK:!SRP";
   ```
 */
@property (nonatomic, copy) NSString *cipher;
/**
   @brief allowed CA certificates.

   If you want to use self-signed certificates etc.,
   set path of CA certificate file like below

    ```
     ctx.cacert = [[NSBundle mainBundle] pathForResource: @"acceptable-ca-list" ofType:@"pem"];
    ```

   @note both PEM and DER are acceptable, and stay nil if there's no need
*/
@property (nonatomic, copy) NSString *cacert;

@end
