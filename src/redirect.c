#include "../include/minishell.h"


void addred(char *str, t_redir **redir, int i, t_data **data)
{
    t_redir *temp;
    t_redir *point;

    temp = malloc(sizeof(t_redir));
    if (str)
        temp->file = ft_strdup(str);
    else
        temp->file = NULL;
    temp->type = i;
    if (i == 2)
        (*data)->herdoc_ishere = true;
    temp->next = NULL;
    if(*redir == NULL || redir == NULL)
    {
        *redir = temp;
        return ;
    }
    point = *redir;
    while (point->next != NULL)
        point = point->next;
    point->next = temp;
}


int addb(t_data **data, char **tab, int i)
{
    int j;
    int k;
    int g;

    j = i;
    k = redd(tab[i]);
    if (track_r1(tab[j]))
    {
        addred(tab[j + 1], &(*data)->redir, redd(tab[j]), data);
        return(j + 2);
    }
    else
    {
        g = 2;
        if (k == 1 || k == 3)
            g = 1;
        addred(tab[j] + g, &(*data)->redir, redd(tab[j]), data);
        return (j + 1);
    }
}

// static void affichered(t_redir **redir)
// {
//     t_redir *temp;

//     temp = NULL;
//     temp = *redir;
//     while (temp)
//     {
//         nbr(temp->type);
//         ft_putchar_fd('\n', 1);
//         ft_putstr_fd(temp->file, 1);
//         ft_putchar_fd('\n', 1);
//         temp = temp->next;
//     }
    
// }

char **resizze(char **tab, int i)
{
    char **tabret;
    int k;

    k = 0;
    tabret = malloc (sizeof(char *) * (i + 1));
    i = 0;
    while (1)
    {
        if (tab[i] == NULL)
        {
            tabret[k] = NULL;
            break;
        }
        if (track_r2(tab[i]))
        {
            if (track_r1(tab[i]))
                i = i + 2;
            else    
                i = i + 1;
        }
        else
            tabret[k++] = ft_strdup(tab[i++]);
    }
    return(tabret);
}

char **finaltab(t_data **data, char **tab)
{
    char **tabret;
    int i;
    int j;

    i = 0;
    j = 0;
    (*data)->redir = NULL;
    while (tab[i])
        if (track_r2(tab[i]))
            i = addb(data, tab, i);
        else
        {
            j++;
            i++;
        }
    tabret = resizze(tab, j);
    // affichered(&(*data)->redir);
    return(tabret);
}


