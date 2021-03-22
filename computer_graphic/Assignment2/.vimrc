" Plugin
set nocompatible
filetype off
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" NERDTree
Plugin 'preservim/nerdtree'

" vim-airline
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'

" git-gutter
Plugin 'airblade/vim-gitgutter'

" Gruv theme
Plugin 'morhetz/gruvbox'

" code completion
"Plugin 'ycm-core/youcompletme'
Plugin 'codota/tabnine-vim'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

"""""""""""""""""""""""""""""""
" Extension specific setup    "
"""""""""""""""""""""""""""""""

let g:airline#extensions#tabline#enabled = 1
map <F2> :NERDTreeToggle<CR>

let g:gruvbox_contrast_dark = 'hard'
" General setting   "
"""""""""""""""""""""
set number
set nowrap
set tabstop=2
set shiftwidth=2
set expandtab
set smartindent
set autoindent
set noswapfile
set noruler
set noshowmode
set laststatus=2
set clipboard=unnamedplus
set clipboard=unnamed
set mouse=a
set backspace=indent,eol,start
set updatetime=500
set timeoutlen=500
syntax enable
syntax on
let mapleader=" "

" new window open on right and below
set splitbelow
set splitright

" case insensitive search unless there is captial letter
set ignorecase
set smartcase

" highlight search result
set hlsearch

" search result update as it is being type
set incsearch

colorscheme gruvbox
set bg=dark

set t_Co=256
""""""""""""""""""""""""""""""""""""""
"   Mapping setting 		     "
""""""""""""""""""""""""""""""""""""""

