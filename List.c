File SubSystem

open() 
close()
creat()
remove()
unlink()
read()
write()
pread()
pwrite()
lseek()
truncate()
ftruncate()
rename()
link()
symlink()
readlink()
sync()
fsync()
fdatasync()

opendir()
closedir()
readdir()       --> read single entry
chdir()
mkdir()
rmdir()
getcwd() 
access()
dup()
dup2() 

stat()
fstat()
lstat()

Memory Management

brk()
sbrk()
memset()
memcmp()
memcpy()
malloc()
calloc()
realloc()
free()
mmap()

process SubSystem

fork()
execl()
getpid()
getppid()
wait()      => used to achive syncronisation parent execution and child death of first child
waitpid()
sleep()
exit()
_exit()
atexit()
nice()
getprority()
setpriority()

// c-startup routuine
