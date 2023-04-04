syntax on

set noerrorbells
set tabstop=4 softtabstop=4
set shiftwidth=4
set noexpandtab
set smartindent
set nu
set nowrap
set smartcase
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch
set foldmethod=indent
set foldlevel=99
set encoding=utf-8
set nocompatible
set splitbelow
set splitright
set path +=**
set wildmenu
set mouse=a 
runtime! ftplugin/man.vim

filetype off

highlight ColorColumn ctermbg=0 guibg=lightgrey

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'gmarik/Vundle.vim'
Plugin 'morhetz/gruvbox'
Plugin 'doums/darcula'
Plugin 'jremmen/vim-ripgrep'
Plugin 'vim-utils/vim-man'
Plugin 'mbbill/undotree'
Plugin 'tmhedberg/SimpylFold'
Plugin 'vim-scripts/indentpython.vim'
Plugin 'nvie/vim-flake8'
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'
Plugin 'szw/vim-maximizer'
Plugin 'dense-analysis/ale'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin '42Paris/42header'


call vundle#end()
filetype plugin indent on


colorscheme gruvbox
set background=dark
" set background transparent
let g:gruvbox_transparent_bg=1
autocmd VimEnter * hi Normal ctermbg=none

if executable('rg')
    let g:rg_derive_roots='true'
endif

let g:ctrlp_user_commad = ['.git/', 'git --git-dir=%s/.git ls-files -oc --exclude-standard'] 
let mapleader = " "
let g:netrw_browse_split=2
let g:netrw_banner = 0
let g:netrw_winsize = 25
let loaded_netrwPlugin = 1

let g:ctrlp_use_caching = 0

nnoremap <leader>h :wincmd h<CR>
nnoremap <leader>j :wincmd j<CR>
nnoremap <leader>k :wincmd k<CR>
nnoremap <leader>l :wincmd l<CR>
nnoremap <leader>u :UndotreeShow<CR>
nnoremap <leader>pv :wincmd v<bar> :Ex <bar>:vertical resize 30 <CR>
nnoremap <leader>ps :Rg<SPACE>
nnoremap <silent> <Leader>= :vertical resize +5<CR>
nnoremap <silent> <Leader>- :vertical resize -5<CR>
nnoremap <silent> <leader>] :resize +5<CR>  
nnoremap <silent> <leader>\ :resize -5<CR>  
nnoremap ff za
inoremap jj <Esc>
nnoremap <C-h> :tabprevious<CR>
nnoremap <C-l> :tabnext<CR>
nnoremap <C-n> :tabnew<CR>
nnoremap <C-c> :tabclose<CR>
nnoremap B <c-v>
tnoremap <leader>h <c-\><c-n><c-w>h
tnoremap <leader>j <c-\><c-n><c-w>j
tnoremap <leader>k <c-\><c-n><c-w>k
tnoremap <leader>l <c-\><c-n><c-w>l

nnoremap <leader>H <C-w>H
nnoremap <leader>J <C-w>J
nnoremap <leader>K <C-w>K
nnoremap <leader>L <C-w>L

""inoremap ( ()<Left>
""inoremap ' ''<Left>
""inoremap " ""<Left>
""inoremap [ []<Left>
""inoremap { {}<Left>
autocmd FileType python map <buffer> <F9> :w<CR>:exec '!python3' shellescape(@%, 1)<CR>
autocmd FileType python imap <buffer> <F9> <esc>:w<CR>:exec '!python3' shellescape(@%, 1)<CR>


" auto-complete goes away when done
let g:ycm_autoclose_preview_window_after_completion=1
" SCut goto Definition
map <leader>g :YcmCompleter GoToDefinitionElseDeclaration<CR>

let g:ycm_collect_identifiers_from_tags_files = 1 " Let YCM read tags from Ctags file
let g:ycm_use_ultisnips_completer = 1 " Default 1, just ensure
let g:ycm_seed_identifiers_with_syntax = 1 " Completion for programming language's keyword
let g:ycm_complete_in_comments = 1 " Completion in comments
let g:ycm_complete_in_strings = 1 " Completion in string

set rtp+=/usr/local/lib/python2.7/dist-packages/powerline/bindings/vim/

" Always show statusline
set laststatus=2

" Use 256 colours (Use this setting only if your terminal supports 256 colours)
set t_Co=256

" auth rewrites files
cnoremap w!! execute 'silent! write !sudo tee % >/dev/null' <bar> edit!

command! MakeTags !ctags -R .

" VIMSPECTOR

let g:vimspector_enable_mappings = 'HUMAN'

"in case I want to maintain configuration outside the vimspector repo
let g:vimspector_base_dir=expand( '$HOME/.vim/vimspector-config' )

nnoremap <leader>n :NERDTree<CR>

nnoremap <leader>m  :MaximizerToggle!<CR>
nnoremap <leader>dd :call vimspector#Launch()<CR>
nnoremap <leader>de :call vimspector#Reset()<CR>

nnoremap <leader>dc :call GotoWindow(g:vimspector_session_windows.code)<CR>
nnoremap <leader>dt :call GotoWindow(g:vimspector_session_windows.tagpage)<CR>
nnoremap <leader>dv :call GoToWindow(g:vimspector_session_windows.variables)<CR>
nnoremap <leader>dw :call GotoWindow(g:vimspector_session_windows.watches)<CR>
nnoremap <leader>ds :call GotoWindow(g:vimspector_session_windows.stack_trace)<CR>
nnoremap <leader>do :call GotoWindow(g:vimspector_session_windows.output)<CR>

nmap <leader>drc <Plug>VimspectorRunToCursor
nmap <leader>dbp <Plug>VimspectorToggleBreakpoint
nmap <leader>dcbp <Plug>VimspectorToggleConditionalBreakpoint

nnoremap <leader>oib :silent !tmux split-window -l 4 "live-server"<CR>

"42 login header
let g:user42 = 'glamazer'
let g:mail42 = 'glamazer@student.42mulhouse.fr'

let g:airline_theme='deus'
let g:airline_powerline_fonts= 1
