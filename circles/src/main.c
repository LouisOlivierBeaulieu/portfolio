#include "application.h"

int main() {
   struct application *application = application_initialize();
   if (application != NULL)
       application_run(application);
   else {
      fprintf(stderr, "Failed to initialize the application...");
      exit(1);
   }
   application_shut_down(application);
   exit(0);
}
