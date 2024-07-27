vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
    use 'wbthomason/packer.nvim'
    use {
        'nvim-telescope/telescope.nvim', tag = '0.1.6',
        requires = { {'nvim-lua/plenary.nvim'} }
    }
    use {
        'ayu-theme/ayu-vim',
        as = 'ayu-vim',
        config = function()
            vim.cmd('set termguicolors')
            vim.cmd('let ayucolor="dark"')
            vim.cmd('colorscheme ayu')
        end
    }
    use 'jiangmiao/auto-pairs'
    use {
        'numToStr/Comment.nvim',
        config = function()
            require('Comment').setup{
                toggler = {
                    line = "<leader>c"
                }
            }
        end
    }
    use 'nvim-tree/nvim-web-devicons'
    use 'romgrk/barbar.nvim'
    use {
        'itchyny/lightline.vim',
        config = function()
            vim.g.lightline = {
                colorscheme = 'molokai'
            }
        end
    }
    use {
        'neovim/nvim-lspconfig',
        config = function()
            local lspconfig = require('lspconfig')
            lspconfig.clangd.setup {}
            lspconfig.texlab.setup {}
        end
    }
    use {
        'SirVer/UltiSnips',
        config = function()
            vim.g.UltiSnipsEditSplit = "vertical"
            vim.g.UltiSnipsForwardTrigger = "<c-b>"
            vim.g.UltiSnipsBackwardTrigger = "<c-z>"
        end
    }
    use {
        "hrsh7th/nvim-cmp",
        requires = {
            "hrsh7th/cmp-buffer", "hrsh7th/cmp-nvim-lsp",
            'quangnguyen30192/cmp-nvim-ultisnips', 'hrsh7th/cmp-nvim-lua',
            'octaltree/cmp-look', 'hrsh7th/cmp-path', 'hrsh7th/cmp-calc',
            'f3fora/cmp-spell', 'hrsh7th/cmp-emoji'
        },
        config = function()
            local cmp = require('cmp')
            cmp.setup {
                completion = {completeopt = 'menu,menuone,noinsert'},
                mapping = cmp.mapping.preset.insert {
                    ['<down>'] = cmp.mapping.select_next_item(),
                    ['<up>'] = cmp.mapping.select_prev_item(),
                    ['<CR>'] = cmp.mapping.confirm {select = true},
                    ['<C-Space>'] = cmp.mapping.complete {},
                },
                sources = {
                    { name = 'nvim_lsp' },
                    { name = 'buffer' },
                    { name = 'path' },
                },
            }
        end
    }
end)
