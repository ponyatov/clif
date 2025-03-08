#pragma once

#ifndef BARE
extern int main(int argc, char *argv[]);
#endif  // BARE

#ifdef __cplusplus
extern "C" {
#endif

extern void arg(int argc, char *argv);  ///< print boot/command line argument
extern void setup(void);                ///<
extern void loop(void);                 ///<

#ifdef __cplusplus
}
#endif
