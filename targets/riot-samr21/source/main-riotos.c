/* Copyright JS Foundation and other contributors, http://js.foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string.h>
#include "shell.h"
#include "jerryscript.h"

/**
 * Jerryscript simple test
 */
int run_js (char * scr)
{
const jerry_char_t script[]="print (hi);";
int i = strlen(scr); i++;
  size_t script_size = strlen ((const char *) script);
  bool ret_value = jerry_run_simple (script, script_size, JERRY_INIT_EMPTY);

  return (ret_value ? 1 : 0);
}

int default_script (int argc, char **argv)
{
 (void) argc;
 (void) argv;
 char c[]="123";
  return (run_js(c));
}


int shell_script (int argc, char **argv)
{
    if (argc < 2) {
        puts("Usage: script <your script here>");
        return -1;
    }
 int count = argc-1;
 char script1[SHELL_DEFAULT_BUFSIZE+1]; 
 strcpy(script1,argv[1]);
 while (count>1) {
     count--;
     strcat(script1," ");
     strcat(script1,argv[argc-count]);
   }
 printf ("Getting script: [%s] of size %u\n\n", script1, strlen (script1)); 
  return (run_js(script1));
} /* test_jerry */

const shell_command_t shell_commands[] = {
  { "test", "Default script ", default_script },
  { "script", "Shell scripting ", shell_script },
  { NULL, NULL, NULL }
};

int main (void)
{
  printf ("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
  printf ("This board features a(n) %s MCU.\n", RIOT_MCU);

  /* start the shell */
  char line_buf[SHELL_DEFAULT_BUFSIZE];
  shell_run (shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

  return 0;
}
