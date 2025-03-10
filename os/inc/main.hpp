#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BARE
extern int main(int argc, char *argv[]);
#endif  // BARE

extern void arg(int argc, char *argv);  ///< print boot/command line argument
extern void setup(void);                ///< single run on system startup
extern void loop(void);                 ///< continuous (event) processing

#ifdef __cplusplus
}
#endif
