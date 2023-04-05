#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	write_error(char *str, char *argv)
{
	int	i;

	i = 0;
	while (str && str[i])
		write(2, &str[i++], 1);
	i = 0;
	if (argv)
		while(argv[i])
			write(2, &argv[i++], 1);
	write(2, "\n", 1);
	return (1);
}

int ft_exec(char **argv, int i, int tmp_fd, char **envp)
{
	argv[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(argv[0], argv, envp);
	return (write_error("execve error:", argv[0]));
}

int main(int argc, char **argv, char **envp)
{
	int i;
	int fd[2];
	int tmp_fd;
	(void)argc;

	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
		    i++;
	        if (!strcmp(argv[0], "cd"))
	        {
	        	if (i != 2)
	               		write_error("cd error: bad argument", NULL);
	            	else if (chdir(argv[1]) != 0)
	            		write_error("cd error: can't change directory to ", argv[1]);
	        }
	        else if (i != 0 && (argv[i] || strcmp(argv[i], ";")) == 0)
	        {
	        	if (fork() == 0)
	        	{
	        		if (ft_exec(argv, i, tmp_fd, envp))
	        			return (1);
	        	}
	        	else
	        	{
	        		close(tmp_fd);
	        		while(waitpid(-1, NULL, WUNTRACED) != -1);
	        		tmp_fd = dup(STDIN_FILENO);
	        	}
	        }
	        else if (i != 0 && !strcmp(argv[i], "|"))
	        {
	        	pipe(fd);
	        	if (fork() == 0)
	        	{
	        		dup2(fd[1], STDOUT_FILENO);
	        		close(fd[0]);
	        		close(fd[1]);
	        		if (ft_exec(argv, i, tmp_fd, envp))
	        			return (1);
	        	}
	        	else
	        	{
	        		close(fd[1]);
	        		close(tmp_fd);
	        		tmp_fd = fd[0];
	        	}
	        }
	}
	close(tmp_fd);
	return (0);
}